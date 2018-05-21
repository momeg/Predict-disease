// 
// Fichier : ListeAttributs.hpp
// Description : D�finition de la classe ListeAttributs.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef LISTEATTRIBUTS_HPP
#define LISTEATTRIBUTS_HPP

#include "Attribut.hpp"

#include <vector>

//
// Classe qui permet de stocker une liste d'attributs
// sans se soucier de la gestion de la m�moire.
//
class ListeAttributs
{
public:
	// Construit une liste d'attributs vide.
	ListeAttributs();

	// Construit une liste d'attributs par copie.
	// Param�tres :
	// - liste : liste � copier.
	ListeAttributs(const ListeAttributs& liste);

	// D�truit la liste d'attributs.
	~ListeAttributs();

public:
	// Op�rateur d'affectation de la liste d'attributs.
	// R�alise une copie de la liste pass�e en param�tre.
	// Param�tres :
	// - liste : liste � copier.
	ListeAttributs& operator=(const ListeAttributs& liste);

public:
	// Supprime tous les attributs de la liste.
	void vider();

	// Ajoute un attribut � la liste. Si un attribut poss�dant
	// le m�me nom existe d�j�, celui-ci est remplac�.
	// Param�tres :
	// - attribut : attribut � ajouter � la liste,
	//   doit �tre un pointeur valide.
	void ajouterAttribut(Attribut* attribut);

	// Donne l'attribut ayant le nom sp�cifi�.
	// S'il n'y a pas d'attribut portant ce nom, renvoie nullptr.
	// Param�tres :
	// - nom : nom de l'attribut � chercher.
	const Attribut* getAttribut(const string& nom) const;

	const Attribut* getAttribut(const int& index) const;

	// Donne une it�rateur pointant sur le premier �l�ment
	// de la liste. Tr�s utile pour parcourir la liste.
	vector<Attribut*>::const_iterator begin() const;

	// Donne une it�rateur pointant apr�s le dernier �l�ment
	// de la liste. Tr�s utile pour parcourir la liste.
	vector<Attribut*>::const_iterator end() const;

private:
	// Conteneur des attributs.
	vector<Attribut*> attributs;
};

#endif // LISTEATTRIBUTS_HPP
