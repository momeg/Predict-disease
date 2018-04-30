#ifndef ATTRIBUT_HPP
#define ATTRIBUT_HPP

#include "TypeAttribut.hpp"

#include <string>

using namespace std;

//
// Classe abstraite qui repr�sente un attribut d'une empreinte.
// Un attribut poss�de un nom, un type et une valeur.
// La valeur d�pend du type de l'attribut et se trouve
// donc uniquement dans les classes filles.
//
class Attribut
{
protected:
	// Construit un attribut.
	// Param�tres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas �tre vide.
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
