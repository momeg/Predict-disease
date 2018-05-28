// 
// Fichier : ListeAttributs.cpp
// Description : Implementation de la classe ListeAttributs.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

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
				cerr << "Erreur lors de la copie d'une liste d'attributs : attribut de type " << attribut->getType() << " inconnu." << endl;
				break;
			}
		}
	}

	return *this;
}

const Attribut* ListeAttributs::operator[](size_t indice) const
{
	if (indice >= attributs.size())
	{
		return nullptr;
	}
	else
	{
		return attributs[indice];
	}
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

	attributs.push_back(attribut);
}

int ListeAttributs::size() const
{
	return attributs.size();
}