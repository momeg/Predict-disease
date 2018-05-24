// 
// Fichier : Attribut.hpp
// Description : D�finition de la classe Attribut.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef DEFINITIONATTRIBUTDOUBLE_HPP
#define DEFINITIONATTRIBUTDOUBLE_HPP

#include "TypeAttribut.hpp"
#include "DefinitionAttribut.hpp"

#include <string>

using namespace std;

//
// Classe abstraite qui repr�sente un attribut d'une empreinte.
// Un attribut poss�de un nom, un type et une valeur.
// La valeur d�pend du type de l'attribut et se trouve
// donc uniquement dans les classes filles.
//
class DefinitionAttributDouble : public DefinitionAttribut
{
public:
	// Construit un attribut.
	// Param�tres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas �tre vide.
	DefinitionAttributDouble(const string& leNom);

	DefinitionAttributDouble();

public:
	// Donne le type de l'attribut.
	const virtual TypeAttribut& getType() const;

public:
	virtual string toString() const;
};

#endif // DEFINITIONATTRIBUTDOUBLE_HPP