// 
// Fichier : Empreinte.cpp
// Description : Impl�mentation de la classe Empreinte.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#include "Empreinte.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"

#include <cassert>
#include <iostream>

Empreinte::Empreinte(){}

Empreinte::Empreinte(int lId, const ListeAttributs& lesAttributs)
	: id(lId),
	attributs(lesAttributs)
{
}

void Empreinte::ajouterMaladie(const string& nomMaladie)
{
	assert(!nomMaladie.empty());

	maladies.insert(nomMaladie);
}

int Empreinte::getId() const
{
	return id;
}

const ListeAttributs& Empreinte::getAttributs() const
{
	return attributs;
}

const Empreinte::ListeMaladies& Empreinte::getMaladies() const
{
	return maladies;
}
