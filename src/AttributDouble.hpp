#ifndef ATTRIBUTDOUBLE_HPP
#define ATTRIBUTDOUBLE_HPP

#include "Attribut.hpp"

//
// Classe qui représente un attribut dont la valeur
// est un nombre à virgule (double).
//
class AttributDouble : public Attribut
{
public:
	// Construit un attribut de type double.
	// Paramètres :
	// - leNom : nom de l'attribut.
	// - laValeur : valeur de l'attribut.
	AttributDouble(const string& leNom, double laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_DOUBLE.
	virtual TypeAttribut getType() const;

public:
	// Donne la valeur de l'attribut.
	double getValeur() const;

private:
	// Valeur de l'attribut.
	double valeur;
};

#endif // ATTRIBUTDOUBLE_HPP
