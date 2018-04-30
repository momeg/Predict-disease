// 
// Fichier : AttributDouble.cpp
// Description : Implémentation de la classe AttributDouble.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#include "AttributDouble.hpp"

AttributDouble::AttributDouble(const string& leNom, double laValeur)
	: Attribut(leNom),
	valeur(laValeur)
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
