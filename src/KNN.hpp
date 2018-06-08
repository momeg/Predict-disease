#ifndef KNN_HPP
#define KNN_HPP

#include "Modele.hpp"

class KNN : public Modele
{
public:
	KNN();

	KNN(unsigned int nbVoisins);

	~KNN();

public:
	virtual Resultat analyserEmpreinte(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, const Empreinte& aTraiter);

private:
	double distanceEmp(const Empreinte& empRef, const Empreinte& empAAnalyser, const CatalogueEmpreintes& catalague);

	double distanceStr(const string& str1, const string& str2);

private:
	unsigned int k;
};

#endif // KNN_HPP
