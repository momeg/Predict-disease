#include "CatalogueMaladies.hpp"

#include <iostream>

CatalogueMaladies::CatalogueMaladies()
{
}

void CatalogueMaladies::afficherGlobale() const
{
	cout << maladies.size() << " maladie(s) répertoriée(s) :" << endl;

	for (auto it = maladies.begin(); it != maladies.end(); it++)
	{
		cout << '\t' << it->second.getNom() << endl;
	}
}

void CatalogueMaladies::afficherParticulier(const string& nomMaladie) const
{
	auto it = maladies.find(nomMaladie);

	if (it == maladies.end())
	{
		cout << "La maladie '" << nomMaladie << "' n'est pas répertoriée." << endl;
	}
	else
	{
		it->second.afficher();
	}
}

void CatalogueMaladies::remplirCatalogue(const CatalogueEmpreintes& empreintes)
{

}
