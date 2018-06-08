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
// Classe qui represente les metadonnees d'un attribut dont la valeur
// est un nombre a virgule (double).
//
class DefinitionAttributDouble : public DefinitionAttribut
{
public:
	// Construit une definition d'attribut de type double.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttributDouble(const string& leNom);

public:
	// Donne la valeur minimale de l'attribut.
	double getMin() const;

	// Donne la valeur maximale de l'attribut.
	double getMax() const;

	// Donne la valeur moyenne de l'attribut.
	double getMoyenne() const;

	// Donne l'ecart-type des valeurs de l'attribut.
	double getEcartType() const;

	// Definit la valeur minimale de l'attribut
	// si celle-ci est inferieure a la valeur actuelle.
	// Parametres :
	// - newMin : la valeur minimale a tester.
	void setMin(double newMin);

	// Definit la valeur maximale de l'attribut
	// si celle-ci est superieure a la valeur actuelle.
	// Parametres :
	// - newMax : la valeur maximale a tester.
	void setMax(double newMax);

	// Definit la valeur moyenne de l'attribut.
	// Parametres :
	// - laMoyenne : la valeur moyenne.
	void setMoyenne(double laMoyenne);

	// Definit l'ecart-type des valeurs de l'attribut.
	// Parametres :
	// - lEcartType : l'ecart-type des valeurs.
	void setEcartType(double lEcartType);

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const;

	// Affiche l'attribut (utilise en test uniquement).
	virtual string toString() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const;

protected:
	// Valeur maximale de l'attribut.
	double max;

	// Valeur minimale de l'attribut.
	double min;

	// Valeur moyenne de l'attribut.
	double moyenne;

	// Ecart-type des valeurs de l'attribut.
	double ecartType;
};

#endif // DEFINITIONATTRIBUTDOUBLE_HPP
