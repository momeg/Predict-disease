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
	// - leNom : nom de l'attribut.
	// - laValeur : valeur de l'attribut.
	AttributString(const string& leNom, const string& laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_STRING.
	virtual TypeAttribut getType() const;

public:
	// Donne la valeur de l'attribut.
	const string& getValeur() const;

private:
	// Valeur de l'attribut.
	string valeur;
};

#endif // ATTRIBUTSTRING_HPP
