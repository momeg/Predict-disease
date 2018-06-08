#ifndef MODELE_HPP
#define MODELE_HPP

#include "Resultat.hpp"
#include "CatalogueEmpreintes.hpp"
#include "CatalogueMaladies.hpp"

class Modele
{
public:
	virtual ~Modele();

protected:
	Modele();

public:
	// Analyse une empreinte, determine ses eventuelles
	// maladies et retourne le resultat du diagnostique.
	// Parametres :
	// - maladiesReference : catalogue de maladies de reference.
	// - reference : catalogue des empreintes de reference.
	// - aTraiter : empreinte a analyser.
	virtual Resultat analyserEmpreinte(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, const Empreinte& aTraiter) = 0;

public:
	vector<Resultat> analyserEmpreintes(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, CatalogueEmpreintes& aTraiter);

	double calculerPrecision(const CatalogueEmpreintes& labeled, const CatalogueEmpreintes& prediction);
};

#endif // MODELE_HPP
