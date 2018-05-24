// 
// Fichier : Attribut.hpp
// Description : D�finition de la classe Attribut.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef DEFINITIONATTRIBUT_HPP
#define DEFINITIONATTRIBUT_HPP

#include "TypeAttribut.hpp"

#include <string>
#include <iostream>

using namespace std;

//
// Classe abstraite qui repr�sente un attribut d'une empreinte.
// Un attribut poss�de un nom, un type et une valeur.
// La valeur d�pend du type de l'attribut et se trouve
// donc uniquement dans les classes filles.
//
class DefinitionAttribut
{
public:
	// Construit un attribut.
	// Param�tres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas �tre vide.
	DefinitionAttribut(const string& leNom);

	DefinitionAttribut();

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const = 0;

	// Donne le nom de l'attribut.
	const string& getNom() const;

	int getIndice() const;

	void setIndice(size_t indice);

public:
	virtual string toString() const;

protected:
	// Nom de l'attribut.
	string nom;
	size_t indice;
};

#endif // DEFINITIONATTRIBUT_HPP
