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
