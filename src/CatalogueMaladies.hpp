#ifndef CATALOGUEMALADIES_HPP
#define CATALOGUEMALADIES_HPP

class CatalogueEmpreintes;

#include "Maladie.hpp"

#include <unordered_map>

//
// Classe qui repr�sente un catalogue de maladies.
// Ce catalogue permet de d�tecter les maladies �
// partir d'un catalogue d'empreintes et de calculer
// leurs symptomes. Il permet �galement d'afficher
// ces maladies.
//
class CatalogueMaladies
{
public:
	// Construit un catalogue vide de maladies.
	CatalogueMaladies();

public:
	// Affiche les noms des maladies dans la sortie standard.
	void afficherGlobale() const;

	// Affiche les caract�ristiques d'une maladie dans la
	// sortie standard. Si la maladie n'existe pas,
	// affiche un message � l'utilisateur.
	// Param�tres :
	// - nomMaladie : nom de la maladie � afficher.
	void afficherParticulier(const string& nomMaladie) const;

	// Remplit le catalogue � partir d'un catalogue d'empreintes.
	// D�tecte les maladies et calcule leurs caract�ristiques.
	// Param�tres :
	// - empreintes : catalogue des empreintes.
	void remplirCatalogue(const CatalogueEmpreintes& empreintes);

private:
	// Conteneur des maladies.
	unordered_map<string, Maladie> maladies;
};

#endif // CATALOGUEMALADIES_HPP
