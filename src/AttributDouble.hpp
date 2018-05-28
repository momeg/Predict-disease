// 
// Fichier : AttributDouble.hpp
// Description : D�finition de la classe AttributDouble.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef ATTRIBUTDOUBLE_HPP
#define ATTRIBUTDOUBLE_HPP

#include "Attribut.hpp"

//
// Classe qui repr�sente un attribut dont la valeur
// est un nombre � virgule (double).
//
class AttributDouble : public Attribut
{
public:
	// Construit un attribut de type double.
	// Param�tres :
	// - laValeur : valeur de l'attribut.
	AttributDouble(double laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_DOUBLE.
	virtual TypeAttribut getType() const;

public:
	// Donne la valeur de l'attribut.
	double getValeur() const;

	// Donne la valeur normalis�e de l'attribut (entre 0 et 1).
	double getValeurNormalisee() const;

	// D�finit la valeur normalis�e de l'attribut.
	// 0 signifie que l'attribut a la valeur minimale
	// de son catalogue et 1 la valeur maximale.
	// Param�tres :
	// - laValeurNormalisee : la valeur normalis�e entre 0 et 1.
	void setValeurNormalisee(double laValeurNormalisee);

	virtual string toString() const;

private:
	// Valeur de l'attribut.
	double valeur;

	// Valeur normalis�e de l'attribut.
	double valeurNormalisee;
};

#endif // ATTRIBUTDOUBLE_HPP
