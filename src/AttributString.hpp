// 
// Fichier : AttributString.hpp
// Description : D�finition de la classe AttributString.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef ATTRIBUTSTRING_HPP
#define ATTRIBUTSTRING_HPP

#include "Attribut.hpp"

//
// Classe qui repr�sente un attribut dont la valeur
// est une cha�ne de caract�res (std::string).
//
class AttributString : public Attribut
{
public:
	// Construit un attribut de type string.
	// Param�tres :
	// - laValeur : valeur de l'attribut.
	AttributString(const string& laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_STRING.
	virtual TypeAttribut getType() const;

public:
	// Donne la valeur de l'attribut.
	const string& getValeur() const;

	virtual string toString() const;

private:
	// Valeur de l'attribut.
	string valeur;
};

#endif // ATTRIBUTSTRING_HPP
