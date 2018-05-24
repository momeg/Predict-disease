// 
// Fichier : ListeDefinitionAttributs.cpp
// Description : Implementation de la classe ListeDefinitionAttributs.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "ListeDefinitionAttributs.hpp"
#include "DefinitionAttributId.hpp"
#include "DefinitionAttributDouble.hpp"
#include "DefinitionAttributString.hpp"

#include <cassert>
#include <iostream>

ListeDefinitionAttributs::ListeDefinitionAttributs()
{
}

ListeDefinitionAttributs::ListeDefinitionAttributs(const ListeDefinitionAttributs& liste)
{
	*this = liste;
}

ListeDefinitionAttributs::~ListeDefinitionAttributs()
{
	vider();
}

ListeDefinitionAttributs& ListeDefinitionAttributs::operator=(const ListeDefinitionAttributs& liste)
{
	if (&liste != this)
	{
		vider();

		for (DefinitionAttribut* definitionAttribut : liste.definitionAttributs)
		{
			switch (definitionAttribut->getType())
			{
            case ATTRIBUT_ID:
				definitionAttributs.push_back(new DefinitionAttributId(*static_cast<DefinitionAttributId*>(definitionAttribut)));
				break;
			case ATTRIBUT_DOUBLE:
				definitionAttributs.push_back(new DefinitionAttributDouble(*static_cast<DefinitionAttributDouble*>(definitionAttribut)));
				break;
			case ATTRIBUT_STRING:
				definitionAttributs.push_back(new DefinitionAttributString(*static_cast<DefinitionAttributString*>(definitionAttribut)));
				break;
			default:
				cerr << "Erreur lors de la copie d'une liste DefinitionAttributs : DefinitionAttribut de type " << definitionAttribut->getType() << " inconnu." << endl;
				break;
			}
		}
	}

	return *this;
}

const DefinitionAttribut* ListeDefinitionAttributs::operator[](size_t indice) const
{
	if (indice >= definitionAttributs.size())
	{
		return nullptr;
	}
	else
	{
		return definitionAttributs[indice];
	}
}

void ListeDefinitionAttributs::vider()
{
	for (DefinitionAttribut* definitionAttribut : definitionAttributs)
	{
		delete definitionAttribut;
	}

	definitionAttributs.clear();
}

int ListeDefinitionAttributs::size()
{
	return definitionAttributs.size();
}

void ListeDefinitionAttributs::ajouterDefinitionAttribut(DefinitionAttribut* definitionAttribut)
{
	assert(definitionAttribut);

	definitionAttributs.push_back(definitionAttribut);
}
