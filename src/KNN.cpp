#include "KNN.h"
using namespace std;

KNN::KNN()
{
	k = 1;// l'algorithme fonctionne avec 1 voisin par defaut 
}

KNN::KNN(unsigned int nbVoisins)
{
	k = nbVoisins;
}

KNN::~KNN()
{
}

vector<Resultat> KNN::analyser(const CatalogueEmpreintes& reference, const CatalogueEmpreintes& aTraiter)
{

}

Resultat KNN::analyser(const CatalogueEmpreintes& reference, const Empreinte& aTraiter)
{
	vector<double> dMins(k);
	for (unsigned int i = 0; i <k; i++) {
		dMins[i] = numeric_limits<double>::max();
	}
	double maxd = numeric_limits<double>::max();
	Resultat res ;
	res.setId(aTraiter.getId);
	double d;
	
	//iterer sur toutes les empreintes du fichier de reference 
	//garder la distance et les maladies associees si la distance fait partie des 
	//k plus petites distances jusqu'a present 
	for (Empreinte empRef : reference.empreintes) {
		d = distanceEmp(empRef, aTraiter);
		if (d < dMins[dMins.size()-1]) {
			dMins[dMins.size() - 1] = d;
			//res.AjouterMaladie(empRef.getMaladies);
			sort(dMins.begin(), dMins.end());
		}
	 }

}

double KNN::distanceEmp(const Empreinte& empRef, const Empreinte& empAAnalyser) {
	double d = 0;//distance entre les 2 empreintes 
	for (unsigned int i = 0; i < empRef.getAttributs.size(); i++) {
		if (empRef.getAttributs[i].typeAttribut() == "ATTRIBUT_STRING")
			d += distanceStr(empRef.getAttributs[i].valeur, empAAnalyser.getAttributs[i].valeur);
		else if (empRef.getAttributs[i].typeAttribut() == "ATTRIBUT_DOUBLE")
			d += empAAnalyser.getAttributs[i].valeur - empRef.getAttributs[i].valeur;
	}
	return d;
}

double distanceStr(const string& str1, const string& str2) {
	if (str1 == str2)
		return 0;
	else
		return 1;
}