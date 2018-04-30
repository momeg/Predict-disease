#include "ListeAttributs.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"

#include <cassert>
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
	vider();
}

ListeAttributs& ListeAttributs::operator=(const ListeAttributs& liste)
{
	if (&liste != this)
	{
		vider();

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

vector<Attribut*>::const_iterator ListeAttributs::begin() const
{
	return attributs.begin();
}

vector<Attribut*>::const_iterator ListeAttributs::end() const
{
	return attributs.end();
}

void ListeAttributs::vider()
{
	for (Attribut* attribut : attributs)
	{
		delete attribut;
	}

	attributs.clear();
}

void ListeAttributs::ajouterAttribut(Attribut* attribut)
{
	assert(attribut);

	for (vector<Attribut*>::iterator it = attributs.begin(); it != attributs.end(); it++)
	{
		if ((*it)->getNom() == attribut->getNom())
		{
			attributs.erase(it);
			break;
		}
	}

	attributs.push_back(attribut);
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
