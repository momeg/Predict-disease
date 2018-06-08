#include "KNN.hpp"
#include "AttributString.hpp"
#include "AttributDouble.hpp"

#include <cassert>
#include <iostream>

static bool distComp(pair<double, set<string> > p1, pair<double, set<string> >  p2) {
	return (p1.first < p2.first);
}

KNN::KNN()
{
	k = 1; // l'algorithme fonctionne avec 1 voisin par defaut
}

KNN::KNN(unsigned int nbVoisins)
{

	assert(nbVoisins != 0);
	k = nbVoisins;
}

KNN::~KNN()
{
}

//analyser une empreinte
Resultat KNN::analyserEmpreinte(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, const Empreinte& aTraiter)
{

	//initialiser dMins a la distance maximale
	set<string> s;
	s.insert("d");
	pair<double, set<string>> p(numeric_limits<double>::max(), s);
	vector< pair<double, set<string> > > dMins(k, p);//vector<pair<distance,set<maladie>>> 
	// contient une distance et la liste des
	// maladies de l'empreinte correspondante


	//for (unsigned int i = 0; i <k; i++) {
		//dMins[i].first = numeric_limits<double>::max();
	//}
	double d;


	//iterer sur toutes les empreintes du fichier de reference
	//garder la distance et les maladies associees si la distance fait partie des
	//k plus petites distances rencontrees jusqu'a present

	for (pair<int, Empreinte> empRef : reference.getEmpreintes()) {
		d = distanceEmp(empRef.second, aTraiter, reference);
		if (d < dMins[dMins.size() - 1].first) {
			dMins[dMins.size() - 1].first = d;
			dMins[dMins.size() - 1].second = empRef.second.getMaladies();
			sort(dMins.begin(), dMins.end(), distComp);
		}
	}

	//calculer les probabilites
	unordered_map <string, double> maladies;// map<maladie,probabilite>
	unordered_map<string, double>::iterator it;
	for (unsigned int i = 0; i < k; i++) {
		for (string s : dMins[i].second) {//parcourir la liste des maladies d'une seule empreinte
			it = maladies.find(s);
			if (it == maladies.end())
				maladies.insert(pair<string, double>(s, 1.0 / k));
			else
				it->second += 1.0 / k;
		}
	}
	vector < pair <string, double> > maladiesVect;

	//transformer le resultat en vecteur
	for (auto elem : maladies) {
		maladiesVect.push_back(pair <string, double>(elem.first, elem.second));
	}
	Resultat res(aTraiter.getId(), maladiesVect);
	return res;
}


double KNN::distanceEmp(const Empreinte& empRef, const Empreinte& empAAnalyser, const CatalogueEmpreintes& catalogue) {
	
	double d = 0;//distance entre les 2 empreintes
	for (const DefinitionAttribut* definition : catalogue.getDefinitionAttribut()) {
		
		unsigned int i = definition->getIndice();
		if (definition->getType() == ATTRIBUT_STRING) {
			
			const string& val = dynamic_cast<const AttributString*>((const Attribut*)(empAAnalyser.getAttributs()[i]))->getValeur();
			const string& valRef = dynamic_cast<const AttributString*>((const Attribut*)(empRef.getAttributs()[i]))->getValeur();
			d += distanceStr(valRef, val);
		}//ATTENTION PAS DE NORMALISATION
		
		else if (definition->getType() == ATTRIBUT_DOUBLE) {
			
			const double val = dynamic_cast<const AttributDouble*>((const Attribut*)(empAAnalyser.getAttributs()[i]))->getValeurNormalisee();//getValeurNormalisee()
			const double valRef = dynamic_cast<const AttributDouble*>((const Attribut*)(empRef.getAttributs()[i]))->getValeurNormalisee();//getValeurNormalisee()
			d += (val - valRef);
		}

	}
	//cout << "############## empreinte num :" << empRef.getId() << "  " << abs(d) << endl;//show distances for debug

	return abs(d);
}

double KNN::distanceStr(const string& str1, const string& str2) {
	if (str1 == str2)
		return 0;
	else
		return 1;
}
