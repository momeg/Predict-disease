// 
// Fichier : CatalogueMaladies.cpp
// Description : Implementation de la classe CatalogueMaladies.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "CatalogueMaladies.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "DefinitionAttributDouble.hpp"
#include "DefinitionAttributString.hpp"

#include <cassert>
#include <iostream>

CatalogueMaladies::CatalogueMaladies()
{
}

void CatalogueMaladies::afficherGlobale() const
{
	cout << maladies.size() << " maladie(s) repertoriee(s) :" << endl;

	for (auto it = maladies.begin(); it != maladies.end(); it++)
	{
		cout << '\t' << it->second.getNom() << endl;
	}
}

void CatalogueMaladies::afficherParticulier(const string& nomMaladie) const
{
	auto it = maladies.find(nomMaladie);

	if (it == maladies.end())
	{
		cout << "La maladie '" << nomMaladie << "' n'est pas repertoriee." << endl;
	}
	else
	{
		it->second.afficher();
	}
}

void CatalogueMaladies::remplirCatalogue(const CatalogueEmpreintes& empreintes)
{
	maladies.clear();

	for (auto it = empreintes.getEmpreintes().begin(); it != empreintes.getEmpreintes().end(); it++)
	{
		for (const string& nomMaladie : it->second.getMaladies())
		{
			if (maladies.find(nomMaladie) == maladies.end())
			{
				ajouterMaladie(empreintes, nomMaladie);
			}
		}
	}
}

void CatalogueMaladies::ajouterMaladie(const CatalogueEmpreintes& empreintes, const string& nomMaladie)
{
	ListeDefinitionAttributs symptomes;

	for (const DefinitionAttribut* definition : empreintes.getDefinitionAttribut())
	{
		if (definition->getType() == ATTRIBUT_DOUBLE)
		{
			// Si l'attribut est un nombre, on calcule l'ecart-type des valeurs
			// et on considere que l'attribut est un symptome de la maladie
			// si l'ecart-type est en dessous d'un certain seuil.

			double somme = 0.0;
			size_t nbEmpreintes = 0;

			for (auto it = empreintes.getEmpreintes().begin(); it != empreintes.getEmpreintes().end(); it++)
			{
				if (it->second.aMaladie(nomMaladie))
				{
					nbEmpreintes++;

					const double valeur = dynamic_cast<const AttributDouble*>((const Attribut*)(it->second.getAttributs()[definition->getIndice()]))->getValeur();
					somme += valeur;
				}
			}

			assert(nbEmpreintes);

			const double moyenne = somme / static_cast<double>(nbEmpreintes);

			somme = 0.0;

			for (auto it = empreintes.getEmpreintes().begin(); it != empreintes.getEmpreintes().end(); it++)
			{
				if (it->second.aMaladie(nomMaladie))
				{
					const double valeur = dynamic_cast<const AttributDouble*>((const Attribut*)(it->second.getAttributs()[definition->getIndice()]))->getValeur();
					somme += (valeur - moyenne) * (valeur - moyenne);
				}
			}

			const double variance = (1.0 / static_cast<double>(nbEmpreintes)) * somme;
			const double ecartType = sqrt(variance);

			const double seuilEcartType = (dynamic_cast<const DefinitionAttributDouble*>(definition)->getMax()
				- dynamic_cast<const DefinitionAttributDouble*>(definition)->getMin()) / 10.0;

			if (ecartType < seuilEcartType)
			{
				DefinitionAttributDouble* symptome = new DefinitionAttributDouble(definition->getNom());
				symptomes.push_back(symptome);
			}
		}
		else if (definition->getType() == ATTRIBUT_STRING)
		{
			// Si l'attribut est une chaîne de caracteres, on calcule la frequence
			// de chaque valeur differente de l'attribut et on considere
			// que l'attribut est un symptome si la frequence d'une valeur
			// est superieure a un certain seuil.

			unordered_map<string, size_t> frequences;
			size_t nbEmpreintes = 0;

			for (auto it = empreintes.getEmpreintes().begin(); it != empreintes.getEmpreintes().end(); it++)
			{
				if (it->second.aMaladie(nomMaladie))
				{
					nbEmpreintes++;

					const string& valeur = dynamic_cast<const AttributString*>((const Attribut*)(it->second.getAttributs()[definition->getIndice()]))->getValeur();

					auto itFrequence = frequences.find(valeur);

					if (itFrequence != frequences.end())
					{
						itFrequence->second++;
					}
					else
					{
						frequences.insert(make_pair(valeur, 1));
					}
				}
			}

			assert(nbEmpreintes);

			const size_t seuilFrequence = nbEmpreintes / 4 * 3;

			if (seuilFrequence)
			{
				for (auto it = frequences.begin(); it != frequences.end(); it++)
				{
					if (it->second > seuilFrequence)
					{
						DefinitionAttributString* symptome = new DefinitionAttributString(definition->getNom());
						symptomes.push_back(symptome);

						break;
					}
				}
			}
		}
	}

	maladies.insert(make_pair(nomMaladie, Maladie(nomMaladie, symptomes)));
}
