// 
// Fichier : CatalogueMaladies.hpp
// Description : Definition de la classe CatalogueMaladies.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef CATALOGUEMALADIES_HPP
#define CATALOGUEMALADIES_HPP

#include "CatalogueEmpreintes.hpp"
#include "Maladie.hpp"

#include <unordered_map>
#include <cmath>
//
// Classe qui represente un catalogue de maladies.
// Ce catalogue permet de detecter les maladies a
// partir d'un catalogue d'empreintes et de calculer
// leurs symptomes. Il permet egalement d'afficher
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

	// Affiche les caracteristiques d'une maladie dans la
	// sortie standard. Si la maladie n'existe pas,
	// affiche un message a l'utilisateur.
	// Parametres :
	// - nomMaladie : nom de la maladie a afficher.
	void afficherParticulier(const string& nomMaladie) const;

	// Remplit le catalogue a partir d'un catalogue d'empreintes.
	// Detecte les maladies et calcule leurs caracteristiques.
	// Parametres :
	// - empreintes : catalogue des empreintes.
	void remplirCatalogue(const CatalogueEmpreintes& empreintes);

private:
	void ajouterMaladie(const CatalogueEmpreintes& empreintes, const string& nomMaladie);

private:
	// Conteneur des maladies.
	unordered_map<string, Maladie> maladies;
};

#endif // CATALOGUEMALADIES_HPP
