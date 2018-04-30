// 
// Fichier : AttributString.hpp
// Description : Définition de la classe AttributString.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef ATTRIBUTSTRING_HPP
#define ATTRIBUTSTRING_HPP

#include "Attribut.hpp"

//
// Classe qui représente un attribut dont la valeur
// est une chaîne de caractères (std::string).
//
class AttributString : public Attribut
{
public:
	// Construit un attribut de type string.
	// Paramètres :
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
