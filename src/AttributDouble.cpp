// 
// Fichier : AttributDouble.cpp
// Description : Impl�mentation de la classe AttributDouble.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
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
