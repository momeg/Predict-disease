// 
// Fichier : Maladie.hpp
// Description : D�finition de la classe Maladie.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef MALADIE_HPP
#define MALADIE_HPP

#include "ListeAttributs.hpp"

//
// Classe qui repr�sente une maladie.
// Une maladie poss�de un nom est des symptomes,
// c'est � dire des attributs qui permettent de l'identifier.
//
class Maladie
{
public:
	// Construit une maladie.
	// Param�tres :
	// - leNom : nom de la maladie.
	// - lesSymptomes : symptomes de la maladie.
	Maladie(const string& leNom, const ListeAttributs& lesSymptomes);

public:
	// Donne le nom de la maladie.
	const string& getNom() const;

	// Affiche la maladie et ses caract�ristiques
	// dans la sortie standard.
	void afficher() const;

private:
	// Nom de la maladie.
	string nom;

	// Symptomes de la maladie.
	ListeAttributs symptomes;
};

#endif // MALADIE_HPP
