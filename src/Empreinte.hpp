// 
// Fichier : Empreinte.hpp
// Description : Définition de la classe Empreinte.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef EMPREINTE_HPP
#define EMPREINTE_HPP

#include "ListeAttributs.hpp"

#include <set>

//
// Classe qui représente une empreinte.
// Une empreinte possède un identifiant (unique),
// des attributs et des maladies associées.
//
class Empreinte
{
public:
	// Type pour stocker les maladies de l'empreinte.
	typedef set<string> ListeMaladies;

public:
	// Construit une empreinte.
	// Paramètres :
	// - lId : identifiant de l'empreinte.
	// - lesAttributs : attributs de l'empreinte.
	Empreinte(int lId, const ListeAttributs& lesAttributs);

public:
	// Ajoute une maladie à l'empreinte. Si l'empreinte
	// possède déjà la maladie, rien ne se passe.
	// Paramètres :
	// - nomMaladie : nom de la maladie à ajouter.
	//   Ce nom ne doit pas être vide.
	void ajouterMaladie(const string& nomMaladie);

	// Donne l'identifiant de l'empreinte.
	int getId() const;

	// Donne les attributs de l'empreinte.
	const ListeAttributs& getAttributs() const;

	// Donne les maladies de l'empreinte.
	const ListeMaladies& getMaladies() const;

private:
	// Identifiant de l'empreinte.
	int id;

	// Attributs de l'empreinte.
	ListeAttributs attributs;

	// Maladies de l'empreinte.
	ListeMaladies maladies;
};

#endif // EMPREINTE_HPP
