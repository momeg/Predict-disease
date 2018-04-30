#include "Empreinte.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"

#include <iostream>

Empreinte::Empreinte(int lId, const ListeMaladies& lesMaladies, const ListeAttributs& lesAttributs)
	: id(lId),
	maladies(lesMaladies),
	attributs(lesAttributs)
{
}

int Empreinte::getId() const
{
	return id;
}

const ListeAttributs& Empreinte::getAttributs() const
{
	return attributs;
}

const Empreinte::ListeMaladies& Empreinte::getMaladies() const
{
	return maladies;
}
