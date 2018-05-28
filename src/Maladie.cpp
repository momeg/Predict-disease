// 
// Fichier : Maladie.cpp
// Description : Implementation de la classe Maladie.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "Maladie.hpp"

#include <iostream>

Maladie::Maladie(const string& leNom, const ListeDefinitionAttributs& lesSymptomes)
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
	cout << "Maladie '" << nom << "' : ";

	if (symptomes.empty())
	{
		cout << "aucun symptome" << endl;
	}
	else
	{
		cout << symptomes.size() << " symptome(s)" << endl;
	}

	for (const DefinitionAttribut* symptome : symptomes)
	{
		cout << "- " << symptome->getNom() << endl;
	}
}
