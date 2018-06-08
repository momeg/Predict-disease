// 
// Fichier : AttributDouble.hpp
// Description : Definition de la classe AttributDouble.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef ATTRIBUTDOUBLE_HPP
#define ATTRIBUTDOUBLE_HPP

#include "Attribut.hpp"

//
// Classe qui represente un attribut dont la valeur
// est un nombre a virgule (double).
//
class AttributDouble : public Attribut
{
public:
	// Construit un attribut de type double.
	// - leNom : nom de l'attribut.
	// - laValeur : valeur de l'attribut.
	AttributDouble(double laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_DOUBLE.
	virtual TypeAttribut getType() const;

	// Retourne un clone de l'attribut.
	virtual Attribut* cloner() const;

public:
	// Donne la valeur de l'attribut.
	double getValeur() const;

	// Donne la valeur normalisee de l'attribut (entre 0 et 1).
	double getValeurNormalisee() const;

	// Definit la valeur normalisee de l'attribut.
	// 0 signifie que l'attribut a la valeur minimale
	// de son catalogue et 1 la valeur maximale.
	// Parametres :
	// - laValeurNormalisee : la valeur normalisee entre 0 et 1.
	void setValeurNormalisee(double laValeurNormalisee);

private:
	// Valeur de l'attribut.
	double valeur;

	// Valeur normalisee de l'attribut.
	double valeurNormalisee;
};

#endif // ATTRIBUTDOUBLE_HPP
