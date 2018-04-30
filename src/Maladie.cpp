// 
// Fichier : Maladie.cpp
// Description : Implémentation de la classe Maladie.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
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
