// 
// Fichier : DefinitionAttributString.hpp
// Description : Definition de la classe DefinitionAttributString.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef DEFINITIONATTRIBUTSTRING_HPP
#define DEFINITIONATTRIBUTSTRING_HPP

#include "DefinitionAttribut.hpp"

//
// 
//
class DefinitionAttributString : public DefinitionAttribut
{
public:
	// Construit un attribut.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttributString(const string& leNom);

	DefinitionAttributString();

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const;

public:
	virtual string toString() const;
};

#endif // DEFINITIONATTRIBUTSTRING_HPP
