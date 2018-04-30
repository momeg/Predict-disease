#include "AttributDouble.hpp"

AttributDouble::AttributDouble(const string& leNom, double laValeur)
	: Attribut(leNom)
{
}

double AttributDouble::getValeur() const
{
	return valeur;
}
