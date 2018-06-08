// 
// Fichier : DefinitionAttributDouble.hpp
// Description : Definition de la classe DefinitionAttributDouble.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef DEFINITIONATTRIBUTDOUBLE_HPP
#define DEFINITIONATTRIBUTDOUBLE_HPP

#include "DefinitionAttribut.hpp"

//
//
//
class DefinitionAttributDouble : public DefinitionAttribut
{
public:
	// Construit un attribut.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttributDouble(const string& leNom);

	DefinitionAttributDouble();

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const;

	double getMin() const;

	double getMax() const;

	void setMin(double newMin);

	void setMax(double newMax);

public:
	virtual string toString() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const;

protected:
	double max;
	double min;
};

#endif // DEFINITIONATTRIBUTDOUBLE_HPP
