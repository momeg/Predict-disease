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

Empreinte::Empreinte(const Empreinte& empreinte)
{
	*this = empreinte;
}

Empreinte::~Empreinte()
{
	for (Attribut* attribut : attributs)
	{
		delete attribut;
	}
}

Empreinte& Empreinte::operator=(const Empreinte& empreinte)
{
	if (&empreinte != this)
	{
		id = empreinte.id;
		maladies = empreinte.maladies;

		attributs.clear();

		for (Attribut* attribut : empreinte.attributs)
		{
			switch (attribut->getType())
			{
			case ATTRIBUT_DOUBLE:
				attributs.push_back(new AttributDouble(*static_cast<AttributDouble*>(attribut)));
				break;
			case ATTRIBUT_STRING:
				attributs.push_back(new AttributString(*static_cast<AttributString*>(attribut)));
				break;
			default:
				cerr << "Erreur lors de la copie de l'empreinte " << empreinte.id << " : type d'attribut " << attribut->getType() << " inconnu." << endl;
				break;
			}
		}
	}

	return *this;
}

int Empreinte::getId() const
{
	return id;
}

const Attribut* Empreinte::getAttribut(const string& nom) const
{
	for (Attribut* attribut : attributs)
	{
		if (attribut->getNom() == nom)
		{
			return attribut;
		}
	}

	return nullptr;
}
