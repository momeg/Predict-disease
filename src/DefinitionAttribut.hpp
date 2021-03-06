// 
// Fichier : DefinitionAttribut.hpp
// Description : Definition de la classe DefinitionAttribut.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef DEFINITIONATTRIBUT_HPP
#define DEFINITIONATTRIBUT_HPP

#include "TypeAttribut.hpp"
#include "PointeurClonable.hpp"

#include <string>
#include <vector>

using namespace std;

//
// Classe abstraite qui represente les metadonnees d'un attribut.
// Un attribut possede un nom, un type ainsi qu'un indice
// dans le tableau des attributs d'une empreinte.
//
class DefinitionAttribut
{
public:
	// Detruit une definition d'attribut.
	virtual ~DefinitionAttribut();

public:
	// Donne le type de l'attribut.
	virtual TypeAttribut getType() const = 0;

	// Donne le nom de l'attribut.
	const string& getNom() const;

	// Donne l'indice de l'attribut.
	size_t getIndice() const;

	// Definit l'indice de l'attribut.
	// Parametres :
	// - indice : indice de l'attribut.
	void setIndice(size_t indice);

public:
	// Affiche l'attribut (utilise en test uniquement).
	virtual string toString() const;

	// Retourne un clone de la definition d'attribut.
	virtual DefinitionAttribut* cloner() const = 0;

protected:
	// Construit une definition d'attribut.
	// Parametres :
	// - leNom : nom de l'attribut. Ce nom ne doit pas etre vide.
	DefinitionAttribut(const string& leNom);

protected:
	// Nom de l'attribut.
	string nom;

	// Indice de l'attribut.
	size_t indice;
};

typedef vector<PointeurClonable<DefinitionAttribut>> ListeDefinitionAttributs;

#endif // DEFINITIONATTRIBUT_HPP
