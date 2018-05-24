// 
// Fichier : AttributDouble.cpp
// Description : Impl�mentation de la classe AttributDouble.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
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

string AttributDouble::toString() const
{
	return to_string(valeur);
}