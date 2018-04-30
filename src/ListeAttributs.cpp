#include "ListeAttributs.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"

#include <iostream>

ListeAttributs::ListeAttributs()
{
}

ListeAttributs::ListeAttributs(const ListeAttributs& liste)
{
	*this = liste;
}

ListeAttributs::~ListeAttributs()
{
	for (Attribut* attribut : attributs)
	{
		delete attribut;
	}
}

ListeAttributs& ListeAttributs::operator=(const ListeAttributs& liste)
{
	if (&liste != this)
	{
		attributs.clear();

		for (Attribut* attribut : liste.attributs)
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
				cerr << "Erreur lors de la copie d'une liste d'attributs : attribut '" << attribut->getNom() << "' de type " << attribut->getType() << " inconnu." << endl;
				break;
			}
		}
	}

	return *this;
}

const Attribut* ListeAttributs::getAttribut(const string& nom) const
{
	for (const Attribut* attribut : attributs)
	{
		if (attribut->getNom() == nom)
		{
			return attribut;
		}
	}

	return nullptr;
}
