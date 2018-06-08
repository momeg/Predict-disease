// 
// Fichier : Maladie.hpp
// Description : Definition de la classe Maladie.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef MALADIE_HPP
#define MALADIE_HPP

#include "DefinitionAttribut.hpp"
#include <algorithm>
//
// Classe qui represente une maladie.
// Une maladie possede un nom est des symptomes,
// c'est a dire des attributs qui permettent de l'identifier.
//
class Maladie
{

public:
	// Construit une maladie.
	// Parametres :
	// - leNom : nom de la maladie.
	// - lesSymptomes : symptomes de la maladie.
	Maladie(const string& leNom, const ListeDefinitionAttributs& lesSymptomes);

	// Donne le nom de la maladie.
	const string& getNom() const;

	// Affiche la maladie et ses caracteristiques
	// sur la sortie standard.
	void afficher() const;

private:
	// Nom de la maladie.
	string nom;

	// Symptomes de la maladie.
	ListeDefinitionAttributs symptomes;
};

#endif // MALADIE_HPP
