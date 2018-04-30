// 
// Fichier : ListeAttributs.hpp
// Description : Définition de la classe ListeAttributs.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef LISTEATTRIBUTS_HPP
#define LISTEATTRIBUTS_HPP

#include "Attribut.hpp"

#include <vector>

//
// Classe qui permet de stocker une liste d'attributs
// sans se soucier de la gestion de la mémoire.
//
class ListeAttributs
{
public:
	// Construit une liste d'attributs vide.
	ListeAttributs();

	// Construit une liste d'attributs par copie.
	// Paramètres :
	// - liste : liste à copier.
	ListeAttributs(const ListeAttributs& liste);

	// Détruit la liste d'attributs.
	~ListeAttributs();

public:
	// Opérateur d'affectation de la liste d'attributs.
	// Réalise une copie de la liste passée en paramètre.
	// Paramètres :
	// - liste : liste à copier.
	ListeAttributs& operator=(const ListeAttributs& liste);

public:
	// Supprime tous les attributs de la liste.
	void vider();

	// Ajoute un attribut à la liste. Si un attribut possédant
	// le même nom existe déjà, celui-ci est remplacé.
	// Paramètres :
	// - attribut : attribut à ajouter à la liste,
	//   doit être un pointeur valide.
	void ajouterAttribut(Attribut* attribut);

	// Donne l'attribut ayant le nom spécifié.
	// S'il n'y a pas d'attribut portant ce nom, renvoie nullptr.
	// Paramètres :
	// - nom : nom de l'attribut à chercher.
	const Attribut* getAttribut(const string& nom) const;

	// Donne une itérateur pointant sur le premier élément
	// de la liste. Très utile pour parcourir la liste.
	vector<Attribut*>::const_iterator begin() const;

	// Donne une itérateur pointant après le dernier élément
	// de la liste. Très utile pour parcourir la liste.
	vector<Attribut*>::const_iterator end() const;

private:
	// Conteneur des attributs.
	vector<Attribut*> attributs;
};

#endif // LISTEATTRIBUTS_HPP
