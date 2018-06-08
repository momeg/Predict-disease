// 
// Fichier : Statistique.cpp
// Description : Implentation de la classe Statistique.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 2 juin 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include "Statistique.hpp"
#include "DefinitionAttributDouble.hpp"
#include "DefinitionAttributString.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"

#include <cassert>

Statistique::Statistique()
{
}

Resultat Statistique::analyserEmpreinte(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, const Empreinte& aTraiter)
{
	vector<pair<string, double>> maladies;

	for (const auto& maladie : maladiesReference.getMaladies())
	{
		size_t nbSymptomes = 0;

		for (const DefinitionAttribut* symptome : maladie.second.getSymptomes())
		{
			if (symptome->getType() == ATTRIBUT_DOUBLE)
			{
				const double valeur = dynamic_cast<const AttributDouble*>((const Attribut*)(aTraiter.getAttributs()[symptome->getIndice()]))->getValeur();

				if (abs(valeur - dynamic_cast<const DefinitionAttributDouble*>(symptome)->getMoyenne()
					<= dynamic_cast<const DefinitionAttributDouble*>(symptome)->getEcartType()))
				{
					nbSymptomes++;
				}
			}
			else if (symptome->getType() == ATTRIBUT_STRING)
			{
				const string& valeur = dynamic_cast<const AttributString*>((const Attribut*)(aTraiter.getAttributs()[symptome->getIndice()]))->getValeur();

				if (valeur == dynamic_cast<const DefinitionAttributString*>(symptome)->getValeurSignificative())
				{
					nbSymptomes++;
				}
			}
		}

		if (nbSymptomes)
		{
			// Si une empreinte possede au moins un symptome on ajoute
			// la maladie avec sa probabilite associee.

			assert(nbSymptomes <= maladie.second.getSymptomes().size());

			const double proba = static_cast<double>(nbSymptomes) / static_cast<double>(maladie.second.getSymptomes().size());

			maladies.push_back(make_pair(maladie.first, proba));
		}
	}

	return Resultat(aTraiter.getId(), maladies);
}
