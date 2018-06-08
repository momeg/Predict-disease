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
// Classe qui represente les metadonnees d'un attribut dont la valeur
// est un ID (entier).
//
class DefinitionAttributId : public DefinitionAttribut
{
public:
	// Construit une definition d'attribut de type ID.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttributId(const string& leNom);

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const;

	// Affiche l'attribut (utilise en test uniquement).
	virtual string toString() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const;
};

#endif // DEFINITIONATTRIBUT_HPP
