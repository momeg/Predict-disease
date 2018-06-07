// 
// Fichier : Empreinte.hpp
// Description : Definition de la classe Empreinte.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef EMPREINTE_HPP
#define EMPREINTE_HPP

#include "Attribut.hpp"
#include <algorithm>
#include <set>

//
// Classe qui represente une empreinte.
// Une empreinte possede un identifiant (unique),
// des attributs et des maladies associees.
//
class Empreinte
{
public:
	// Type pour stocker les maladies de l'empreinte.
	typedef set<string> ListeMaladies;

public:
	Empreinte();

	// Construit une empreinte.
	// Parametres :
	// - lId : identifiant de l'empreinte.
	// - lesAttributs : attributs de l'empreinte.
	Empreinte(int lId, const ListeAttributs& lesAttributs);

public:
	// Ajoute une maladie a l'empreinte. Si l'empreinte
	// possede deja la maladie, rien ne se passe.
	// Parametres :
	// - nomMaladie : nom de la maladie a ajouter.
	//   Ce nom ne doit pas etre vide.
	void ajouterMaladie(const string& nomMaladie);

	// Donne l'identifiant de l'empreinte.
	int getId() const;

	// Donne les attributs de l'empreinte.
	const ListeAttributs& getAttributs() const;

	// Donne les attributs de l'empreinte.
	void setAttributIndice(Attribut* unAttribut, int indice);

	// Donne les maladies de l'empreinte.
	const ListeMaladies& getMaladies() const;

	bool aMaladie(const string& nomMaladie) const;

private:
	// Identifiant de l'empreinte.
	int id;

	// Attributs de l'empreinte.
	ListeAttributs attributs;

	// Maladies de l'empreinte.
	ListeMaladies maladies;
};

#endif // EMPREINTE_HPP
