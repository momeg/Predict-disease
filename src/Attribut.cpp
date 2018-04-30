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
