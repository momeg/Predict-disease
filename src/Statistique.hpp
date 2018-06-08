// 
// Fichier : Statistique.hpp
// Description : Definition de la classe Statistique.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 2 juin 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef STATISTIQUE_HPP
#define STATISTIQUE_HPP

#include "Modele.hpp"

//
// La classe Statistique permet d'analyser des empreintes
// et de determiner leurs maladies a partir des
// statistiques stockees dans CatalogueMaladies.
//
class Statistique : public Modele
{
public:
	// Construit un algo Statistique.
	Statistique();

public:
	// Analyse une empreinte, determine ses eventuelles
	// maladies et retourne le resultat du diagnostique.
	// Parametres :
	// - maladiesReference : catalogue de maladies de reference.
	// - reference : catalogue des empreintes de reference.
	// - aTraiter : empreinte a analyser.
	virtual Resultat analyserEmpreinte(const CatalogueMaladies& maladiesReference, const CatalogueEmpreintes& reference, const Empreinte& aTraiter);
};

#endif // STATISTIQUE_HPP
