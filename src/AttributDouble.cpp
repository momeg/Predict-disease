// 
// Fichier : AttributDouble.cpp
// Description : Implémentation de la classe AttributDouble.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
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
