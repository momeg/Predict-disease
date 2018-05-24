// 
// Fichier : ListeAttributs.hpp
// Description : Definition de la classe ListeAttributs.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef LISTEDEFINITIONATTRIBUTS_HPP
#define LISTEDEFINITIONATTRIBUTS_HPP

#include "DefinitionAttribut.hpp"

#include <vector>

//
// Classe qui permet de stocker une liste d'attributs
// sans se soucier de la gestion de la memoire.
//
class ListeDefinitionAttributs
{
public:
	// Construit une liste d'attributs vide.
	ListeDefinitionAttributs();

	// Construit une liste d'attributs par copie.
	// Parametres :
	// - liste : liste a copier.
	ListeDefinitionAttributs(const ListeDefinitionAttributs& liste);

	// Detruit la liste d'attributs.
	~ListeDefinitionAttributs();

public:
	// Operateur d'affectation de la liste d'attributs.
	// Realise une copie de la liste passee en parametre.
	// Parametres :
	// - liste : liste a copier.
	ListeDefinitionAttributs& operator=(const ListeDefinitionAttributs& liste);

	// Donne l'attribut à l'indice donné ou null si
	// l'indice n'est pas valide.
	// Paramètres :
	// - indice : indice de l'attribut à récupérer.
	const DefinitionAttribut* operator[](size_t indice) const;

public:
	// Supprime tous les attributs de la liste.
	void vider();

	int size();

	// Ajoute un attribut a la liste. Si un attribut possedant
	// le meme nom existe deja, celui-ci est remplace.
	// Parametres :
	// - attribut : attribut a ajouter  la liste,
	//   doit etre un pointeur valide.
	void ajouterDefinitionAttribut(DefinitionAttribut* definitionAttribut);

private:
	// Conteneur des attributs.
	vector<DefinitionAttribut*> definitionAttributs;
};

#endif // LISTEDEFINITIONATTRIBUTS_HPP
