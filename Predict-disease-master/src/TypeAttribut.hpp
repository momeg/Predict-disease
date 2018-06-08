// 
// Fichier : TypeAttribut.hpp
// Description : Definition de l'enumeration TypeAttribut.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#ifndef TYPEATTRIBUT_HPP
#define TYPEATTRIBUT_HPP

//
// Enumeration qui contient les differents types d'attributs existants.
//
enum TypeAttribut
{
	// Identifiant unique de l'empreinte.
	ATTRIBUT_ID,

	// Nombre a virgule (double).
	ATTRIBUT_DOUBLE,

	// Chaine de caracteres (std::string).
	ATTRIBUT_STRING
};

#endif // TYPEATTRIBUT_HPP
