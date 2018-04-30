// 
// Fichier : Attribut.cpp
// Description : Implémentation de la classe Attribut.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#include "Attribut.hpp"

#include <cassert>

Attribut::Attribut(const string& leNom)
	: nom(leNom)
{
	assert(!nom.empty());
}

const string& Attribut::getNom() const
{
	return nom;
}
