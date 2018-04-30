#include "Attribut.hpp"

Attribut::Attribut(const string& leNom)
	: nom(leNom)
{
}

const string& Attribut::getNom() const
{
	return nom;
}
