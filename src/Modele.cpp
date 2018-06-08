#include "Modele.hpp"

Modele::Modele()
{
}

Modele::~Modele()
{
}

vector<Resultat> Modele::analyserEmpreintes(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, CatalogueEmpreintes& aTraiter)
{
	vector<Resultat> res;

	for (const pair<int, Empreinte>& e : aTraiter.getEmpreintes())
	{
		res.push_back(analyserEmpreinte(maladiesReference, reference, e.second));
	}

	return res;
}

double Modele::calculerPrecision(const CatalogueEmpreintes& labeled, const CatalogueEmpreintes& prediction)
{
	Empreinte empPred;
	double precision;
	int nbOk = 0;
	int nb = 0;
	for (pair<int, Empreinte> empLabeled : labeled.getEmpreintes()) {
		nb++;
		empPred = prediction.getEmpreintes().find(empLabeled.first)->second;
		if (empPred.getMaladies() == empLabeled.second.getMaladies()) {
			nbOk++;
		}
	}
	precision = nbOk / (1.0*nb);
	return precision;
}

/**
for (pair<int, Empreinte> empRef : reference.getEmpreintes()) {
	d = distanceEmp(empRef.second,  aTraiter, reference);
*/
