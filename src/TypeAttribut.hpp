// 
// Fichier : TypeAttribut.hpp
// Description : D�finition de l'�num�ration TypeAttribut.
// Auteur : Lo�c Saos (loic.saos@insa-lyon.fr).
// Date de cr�ation : 30 avril 2018
// Versions :
// - 1.0 : Cr�ation de la classe.
//

#ifndef TYPEATTRIBUT_HPP
#define TYPEATTRIBUT_HPP

//
// Enumeration qui contient les diff�rents types d'attributs existants.
//
enum TypeAttribut
{
	// Identifiant unique de l'empreinte.
	ATTRIBUT_ID,

	// Nombre � virgule (double).
	ATTRIBUT_DOUBLE,

	// Cha�ne de caract�res (std::string).
	ATTRIBUT_STRING
};

#endif // TYPEATTRIBUT_HPP
