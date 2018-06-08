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
// Classe qui represente les metadonnees d'un attribut dont la valeur
// est une chaine de caracteres (std::string).
//
class DefinitionAttributString : public DefinitionAttribut
{
public:
	// Construit une definition d'attribut de type string.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttributString(const string& leNom);

	// Donne la valeur significative de l'attribut,
	// c'est la valeur majoritairement presente si
	// elle existe, sinon une string vide.
	const string& getValeurSignificative() const;

	// Definit la valeur significative de l'attribut.
	// Parametres :
	// - laValeurSignificative : la valeur significative.
	void setValeurSignificative(const string& laValeurSignificative);

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const;

	// Affiche l'attribut (utilise en test uniquement).
	virtual string toString() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const;

private:
	// Valeur significative de l'attribut.
	string valeurSignificative;
};

#endif // DEFINITIONATTRIBUTSTRING_HPP
