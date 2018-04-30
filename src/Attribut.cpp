// 
// Fichier : Attribut.cpp
// Description : Impl�mentation de la classe Attribut.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
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
