// 
// Fichier : TypeAttribut.hpp
// Description : Définition de l'énumération TypeAttribut.
// Auteur : Loïc Saos (loic.saos@insa-lyon.fr).
// Date de création : 30 avril 2018
// Versions :
// - 1.0 : Création de la classe.
//

#ifndef TYPEATTRIBUT_HPP
#define TYPEATTRIBUT_HPP

//
// Enumeration qui contient les différents types d'attributs existants.
//
enum TypeAttribut
{
	// Identifiant unique de l'empreinte.
	ATTRIBUT_ID,

	// Nombre à virgule (double).
	ATTRIBUT_DOUBLE,

	// Chaîne de caractères (std::string).
	ATTRIBUT_STRING
};

#endif // TYPEATTRIBUT_HPP
