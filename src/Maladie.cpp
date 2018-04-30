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
