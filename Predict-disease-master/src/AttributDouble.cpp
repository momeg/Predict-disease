// 
// Fichier : AttributDouble.cpp
// Description : Implementation de la classe AttributDouble.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "AttributDouble.hpp"

#include <cassert>

AttributDouble::AttributDouble(double laValeur)
	: valeur(laValeur),
	valeurNormalisee(0.0)
{
}

TypeAttribut AttributDouble::getType() const
{
	return ATTRIBUT_DOUBLE;
}

Attribut* AttributDouble::cloner() const
{
	return new AttributDouble(*this);
}

double AttributDouble::getValeur() const
{
	return valeur;
}

double AttributDouble::getValeurNormalisee() const
{
	return valeurNormalisee;
}

void AttributDouble::setValeurNormalisee(double laValeurNormalisee)
{
	assert(laValeurNormalisee >= 0.0 && laValeurNormalisee <= 1.0f);
	valeurNormalisee = laValeurNormalisee;
}
