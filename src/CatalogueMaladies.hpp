#ifndef CATALOGUEMALADIES_HPP
#define CATALOGUEMALADIES_HPP

class CatalogueEmpreintes;

#include "Maladie.hpp"

#include <unordered_map>

class CatalogueMaladies
{
public:
	CatalogueMaladies();

public:
	void afficherGlobale() const;

	void afficherParticulier(const string& nomMaladie) const;

	void remplirCatalogue(const CatalogueEmpreintes& empreintes);

private:
	unordered_map<string, Maladie> maladies;
};

#endif // CATALOGUEMALADIES_HPP
