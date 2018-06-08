// 
// Fichier : DefinitionAttributDouble.cpp
// Description : Implementation de la classe DefinitionAttributDouble.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "DefinitionAttributDouble.hpp"

DefinitionAttributDouble::DefinitionAttributDouble(const string& leNom)
	: DefinitionAttribut(leNom),
	max(numeric_limits<double>::min()),
	min(numeric_limits<double>::max()),
	moyenne(0.0),
	ecartType(0.0)
{
}

TypeAttribut DefinitionAttributDouble::getType() const
{
	return ATTRIBUT_DOUBLE;
}

void DefinitionAttributDouble::setMax(double newMax)
{
	if (newMax > max)
	{
		max = newMax;
	}
}

void DefinitionAttributDouble::setMin(double newMin)
{
	if (newMin < min)
	{
		min = newMin;
	}
}

double DefinitionAttributDouble::getMax() const
{
	return max;
}

double DefinitionAttributDouble::getMin() const
{
	return min;
}

string DefinitionAttributDouble::toString() const
{
	return DefinitionAttribut::toString() + " : double";
}

DefinitionAttribut* DefinitionAttributDouble::cloner() const
{
	return new DefinitionAttributDouble(*this);
}

double DefinitionAttributDouble::getMoyenne() const
{
	return moyenne;
}

double DefinitionAttributDouble::getEcartType() const
{
	return ecartType;
}

void DefinitionAttributDouble::setMoyenne(double laMoyenne)
{
	moyenne = laMoyenne;
}

void DefinitionAttributDouble::setEcartType(double lEcartType)
{
	ecartType = lEcartType;
}
