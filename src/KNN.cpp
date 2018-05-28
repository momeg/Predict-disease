#include "KNN.hpp"

using namespace std;

KNN::KNN()
{
	k = 1;// l'algorithme fonctionne avec 1 voisin par defaut
}

KNN::KNN(unsigned int nbVoisins)
{
	assert(k != 0);
	k = nbVoisins;
}

KNN::~KNN()
{
}

//analyser plusieures empreintes
vector<Resultat> KNN::analyser(const CatalogueEmpreintes& reference, const CatalogueEmpreintes& aTraiter)
{
	vector<Resultat> res;

	for (pair<int, Empreinte> e : aTraiter.getEmpreintes()) {
		res.push_back(analyser(reference, e.second));
	}
	return res;
}

//analyser une empreinte
Resultat KNN::analyser(const CatalogueEmpreintes& reference, const Empreinte& aTraiter)
{
	//Initialize dMins with max distance
	set<string> s;
	s.insert("d");
	pair<double, set<string>> p(numeric_limits<double>::max(), s);
	vector< pair<double,set<string> > > dMins(k, p);//vector<pair<distance,set<maladie>>> distance et la liste des
	//maladies de l'empreinte correspondates


	//for (unsigned int i = 0; i <k; i++) {
		//dMins[i].first = numeric_limits<double>::max();
	//}
	double maxd = numeric_limits<double>::max();
	double d;

	//iterer sur toutes les empreintes du fichier de reference
	//garder la distance et les maladies associees si la distance fait partie des
	//k plus petites distances jusqu'a present
	for (pair<int, Empreinte> empRef : reference.getEmpreintes()) {
		d = distanceEmp(empRef.second,  aTraiter, reference);
		if (d < dMins[dMins.size()-1].first) {
			dMins[dMins.size() - 1].first = d;
			dMins[dMins.size() - 1].second = empRef.second.getMaladies();
			sort(dMins.begin(), dMins.end(),distComp);
		}
	 }
	//calculer les probabilites
	unordered_map <string,double> maladies;//map<maladie,probabilite>
	unordered_map<string, double>::iterator it;
	for (unsigned int i = 0; i < k; i++) {
		for(string s : dMins[i].second){//partcourir la liste des maladies d'une seule empreinte
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

bool distComp(pair<double, set<string> > p1, pair<double, set<string> >  p2) {
	return (p1.first<p2.first);

}


double KNN::distanceEmp(const Empreinte& empRef, const Empreinte& empAAnalyser,const CatalogueEmpreintes& catalogue) {
	double d = 0;//distance entre les 2 empreintes
	for (const DefinitionAttribut* definition : empreintes.getDefinitionAttribut()){
		unsigned int i = definition.getIndice();
		if (definition->getType() == ATTRIBUT_STRING) {
			const string& val = dynamic_cast<const AttributString*>((const Attribut*)(empAAnalyser.getAttributs()[i]))->getValeur();
			const string& valRef = dynamic_cast<const AttributString*>((const Attribut*)(empRef.getAttributs()[i]))->getValeur();
			d += distanceStr(valRef, val);
		}
		else if (definition->getType() == ATTRIBUT_DOUBLE) {
			const double val = dynamic_cast<const AttributDouble*>((const Attribut*)(empAAnalyser.getAttributs()[i]))->getValeurNormalisee();
			const double valRef = dynamic_cast<const AttributDouble*>((const Attribut*)(empRef.getAttributs()[i]))->getValeurNormalisee();
			d += (val - valRef);
		}

	}
	return d;
}

double KNN::distanceStr(const string& str1, const string& str2) {
	if (str1 == str2)
		return 0;
	else
		return 1;
}
