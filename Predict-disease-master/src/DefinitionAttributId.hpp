// 
// Fichier : DefinitionAttributId.hpp
// Description : Definition de la classe DefinitionAttributId.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef DEFINITIONATTRIBUTID_HPP
#define DEFINITIONATTRIBUTID_HPP

#include "DefinitionAttribut.hpp"


//
// 
//
class DefinitionAttributId : public DefinitionAttribut
{
public:
	// Construit un attribut.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttributId(const string& leNom);

	DefinitionAttributId();

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const;

public:
	virtual string toString() const;
};

#endif // DEFINITIONATTRIBUT_HPP
