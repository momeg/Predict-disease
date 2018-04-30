#ifndef ATTRIBUT_HPP
#define ATTRIBUT_HPP

#include "TypeAttribut.hpp"

#include <string>

using namespace std;

//
// Classe abstraite qui représente un attribut d'une empreinte.
// Un attribut possède un nom, un type et une valeur.
// La valeur dépend du type de l'attribut et se trouve
// donc uniquement dans les classes filles.
//
class Attribut
{
protected:
	// Construit un attribut.
	// Paramètres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas être vide.
	Attribut(const string& leNom);

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const = 0;

public:
	// Donne le nom de l'attribut.
	const string& getNom() const;

private:
	// Nom de l'attribut.
	string nom;
};

#endif // ATTRIBUT_HPP
