// 
// Fichier : AttributString.hpp
// Description : Definition de la classe AttributString.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef ATTRIBUTSTRING_HPP
#define ATTRIBUTSTRING_HPP

#include "Attribut.hpp"

//
// Classe qui represente un attribut dont la valeur
// est une chaîne de caracteres (std::string).
//
class AttributString : public Attribut
{
public:
	// Construit un attribut de type string.
	// Parametres :
	// - laValeur : valeur de l'attribut.
	AttributString(const string& laValeur);

public:
	// Donne le type de l'attribut.
	// Dans ce cas, retourne toujours ATTRIBUT_STRING.
	virtual TypeAttribut getType() const;

	// Retourne un clone de l'attribut.
	virtual Attribut* cloner() const;

public:
	// Donne la valeur de l'attribut.
	const string& getValeur() const;

private:
	// Valeur de l'attribut.
	string valeur;
};

#endif // ATTRIBUTSTRING_HPP
