// 
// Fichier : Attribut.hpp
// Description : Définition de la classe Attribut.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef ATTRIBUT_HPP
#define ATTRIBUT_HPP

#include "TypeAttribut.hpp"

#include <string>

using namespace std;

//
// Classe abstraite qui représente un attribut d'une empreinte.
// Un attribut possède un type et une valeur.
// La valeur dépend du type de l'attribut et se trouve
// donc uniquement dans les classes filles.
//
class Attribut
{
protected:
	// Construit un attribut.
	Attribut();

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const = 0;
};

#endif // ATTRIBUT_HPP
