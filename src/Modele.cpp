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

double Modele::calculerPrecision(const CatalogueEmpreintes& labeled, const vector<Resultat>& resultats)
{
	Empreinte empPred;
	double precision;
	int nbOk = 0;
	int nb = 0;

	//recuperer la liste des maladie de chaque resultat et la transformer en set
	for (Resultat res : resultats) {
		nb++;
		set<string> maladiesRes;
		for (pair<string, double> p : res.getMaladies()) {
			if (p.second > 0.5) {
				maladiesRes.insert(p.first);
			}
		}
		Empreinte empLabeled = labeled.getEmpreintes().find(res.getId())->second;
		if (maladiesRes == empLabeled.getMaladies()) {
			nbOk++;
		}
	}
	precision = nbOk / (1.0*nb);
	return precision;
}
