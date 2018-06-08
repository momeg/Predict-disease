// 
// Fichier : PointeurClonable.hpp
// Description : Definition de la classe PointeurClonable.
// Auteur : Loic Saos (loic.saos@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#pragma once

//
// Classe template utilitaire permettant de copier
// en profondeur des pointeurs automatiquement.
// La classe mere doit definir la methode virtuelle
// pure cloner et les classes filles doivent
// l'implementer.
//
template<typename ClasseMere>
class PointeurClonable
{
public:
	// Construit un pointeur vide (nullptr). 
	PointeurClonable()
		: pointeur(nullptr)
	{
	}

	// Construit le pointeur a partir d'un
	// pointeur brut sur un objet.
	// Parametres :
	// - lePointeur : pointeur a stocker.
	PointeurClonable(ClasseMere* lePointeur)
		: pointeur(lePointeur)
	{
	}

	// Constructeur de copie, realise une copie
	// en profondeur.
	// Parametres :
	// - pointeurClonable : pointeur a cloner.
	PointeurClonable(const PointeurClonable& pointeurClonable)
	{
		const ClasseMere* const ptr = pointeurClonable;

		if (ptr)
		{
			pointeur = ptr->cloner();
		}
		else
		{
			pointeur = nullptr;
		}
	}

	// Constructeur de deplacement.
	// Parametres :
	// - pointeurClonable : pointeur a deplacer.
	PointeurClonable(PointeurClonable&& pointeurClonable)
	{
		pointeur = pointeurClonable.pointeur;
		pointeurClonable.pointeur = nullptr;
	}

	// Detruit le pointeur et l'objet pointe.
	~PointeurClonable()
	{
		if (pointeur)
		{
			delete pointeur;
		}
	}

public:
	// Operateur d'affectation depuis un pointeur brut.
	// Parametres :
	// - lePointeur : pointeur a stocker.
	PointeurClonable& operator=(ClasseMere* lePointeur)
	{
		if (pointeur)
		{
			delete pointeur;
		}

		pointeur = lePointeur;

		return *this;
	}

	// Operateur d'affectation, realise une copie
	// en profondeur.
	// Parametres :
	// - pointeurClonable : pointeur a cloner.
	PointeurClonable& operator=(const PointeurClonable& pointeurClonable)
	{
		if (*this != pointeurClonable)
		{
			if (pointeur)
			{
				delete pointeur;
			}

			const ClasseMere* const ptr = pointeurClonable;

			if (ptr)
			{
				pointeur = ptr->cloner();
			}
			else
			{
				pointeur = nullptr;
			}
		}

		return *this;
	}

	// Donne le pointeur brut.
	operator ClasseMere*()
	{
		return pointeur;
	}

	// Donne le pointeur brut constant.
	operator const ClasseMere*() const
	{
		return pointeur;
	}

	// Accede au pointeur brut.
	ClasseMere* operator ->()
	{
		return pointeur;
	}

	// Accede au pointeur brut constant.
	const ClasseMere* operator ->() const
	{
		return pointeur;
	}

private:
	// Pointeur brut vers l'objet stocke.
	ClasseMere* pointeur;
};
