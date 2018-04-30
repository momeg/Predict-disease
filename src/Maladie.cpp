// 
// Fichier : Maladie.cpp
// Description : Impl�mentation de la classe Maladie.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#include "Maladie.hpp"

#include <iostream>

Maladie::Maladie(const string& leNom, const ListeAttributs& lesSymptomes)
	: nom(leNom),
	symptomes(lesSymptomes)
{
}

const string& Maladie::getNom() const
{
	return nom;
}

void Maladie::afficher() const
{
	cout << "Affichage de la maladie '" << nom << "'" << endl;
}
