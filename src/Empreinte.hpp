// 
// Fichier : Empreinte.hpp
// Description : D�finition de la classe Empreinte.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef EMPREINTE_HPP
#define EMPREINTE_HPP

#include "ListeAttributs.hpp"

#include <set>

//
// Classe qui repr�sente une empreinte.
// Une empreinte poss�de un identifiant (unique),
// des attributs et des maladies associ�es.
//
class Empreinte
{
public:
	// Type pour stocker les maladies de l'empreinte.
	typedef set<string> ListeMaladies;

public:
	Empreinte();

	// Construit une empreinte.
	// Param�tres :
	// - lId : identifiant de l'empreinte.
	// - lesAttributs : attributs de l'empreinte.
	Empreinte(int lId, const ListeAttributs& lesAttributs);

public:
	// Ajoute une maladie � l'empreinte. Si l'empreinte
	// poss�de d�j� la maladie, rien ne se passe.
	// Param�tres :
	// - nomMaladie : nom de la maladie � ajouter.
	//   Ce nom ne doit pas �tre vide.
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
