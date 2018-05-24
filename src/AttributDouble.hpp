// 
// Fichier : AttributDouble.hpp
// Description : Dï¿½finition de la classe AttributDouble.
// Auteur : Loï¿½c Saos (loic.saos@insa-lyon.fr).
// Date de crï¿½ation : 30 avril 2018
// Versions :
// - 1.0 : Crï¿½ation de la classe.
//

#ifndef ATTRIBUTDOUBLE_HPP
#define ATTRIBUTDOUBLE_HPP

#include "Attribut.hpp"

//
// Classe qui reprï¿½sente un attribut dont la valeur
// est un nombre ï¿½ virgule (double).
//
class AttributDouble : public Attribut
{
public:
	// Construit un attribut de type double.
<<<<<<< HEAD
	// Paramètres :
=======
	// Paramï¿½tres :
	// - leNom : nom de l'attribut.
>>>>>>> 115611d0d163ca73843a4d1babb0f4fc78308781
	// - laValeur : valeur de l'attribut.
	AttributDouble(double laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_DOUBLE.
	virtual TypeAttribut getType() const;

public:
	// Donne la valeur de l'attribut.
	double getValeur() const;

	// Donne la valeur normalisée de l'attribut (entre 0 et 1).
	double getValeurNormalisee() const;

	// Définit la valeur normalisée de l'attribut.
	// 0 signifie que l'attribut a la valeur minimale
	// de son catalogue et 1 la valeur maximale.
	// Paramètres :
	// - laValeurNormalisee : la valeur normalisée entre 0 et 1.
	void setValeurNormalisee(double laValeurNormalisee);

private:
	// Valeur de l'attribut.
	double valeur;

	// Valeur normalisée de l'attribut.
	double valeurNormalisee;
};

#endif // ATTRIBUTDOUBLE_HPP
