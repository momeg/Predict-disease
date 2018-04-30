// 
// Fichier : CatalogueMaladies.hpp
// Description : Définition de la classe CatalogueMaladies.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef CATALOGUEMALADIES_HPP
#define CATALOGUEMALADIES_HPP

#include "CatalogueEmpreintes.hpp"
#include "Maladie.hpp"

#include <unordered_map>

//
// Classe qui représente un catalogue de maladies.
// Ce catalogue permet de détecter les maladies à
// partir d'un catalogue d'empreintes et de calculer
// leurs symptomes. Il permet également d'afficher
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

	// Affiche les caractéristiques d'une maladie dans la
	// sortie standard. Si la maladie n'existe pas,
	// affiche un message à l'utilisateur.
	// Paramètres :
	// - nomMaladie : nom de la maladie à afficher.
	void afficherParticulier(const string& nomMaladie) const;

	// Remplit le catalogue à partir d'un catalogue d'empreintes.
	// Détecte les maladies et calcule leurs caractéristiques.
	// Paramètres :
	// - empreintes : catalogue des empreintes.
	void remplirCatalogue(const CatalogueEmpreintes& empreintes);

private:
	// Conteneur des maladies.
	unordered_map<string, Maladie> maladies;
};

#endif // CATALOGUEMALADIES_HPP
