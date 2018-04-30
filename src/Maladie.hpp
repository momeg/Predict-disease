// 
// Fichier : Maladie.hpp
// Description : Définition de la classe Maladie.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef MALADIE_HPP
#define MALADIE_HPP

#include "ListeAttributs.hpp"

//
// Classe qui représente une maladie.
// Une maladie possède un nom est des symptomes,
// c'est à dire des attributs qui permettent de l'identifier.
//
class Maladie
{
public:
	// Construit une maladie.
	// Paramètres :
	// - leNom : nom de la maladie.
	// - lesSymptomes : symptomes de la maladie.
	Maladie(const string& leNom, const ListeAttributs& lesSymptomes);

public:
	// Donne le nom de la maladie.
	const string& getNom() const;

	// Affiche la maladie et ses caractéristiques
	// dans la sortie standard.
	void afficher() const;

private:
	// Nom de la maladie.
	string nom;

	// Symptomes de la maladie.
	ListeAttributs symptomes;
};

#endif // MALADIE_HPP
