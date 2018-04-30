#ifndef MALADIE_HPP
#define MALADIE_HPP

#include "ListeAttributs.hpp"

class Maladie
{
public:
	Maladie(const string& leNom, const ListeAttributs& lesSymptomes);

public:
	const string& getNom() const;

	void afficher() const;

private:
	string nom;

	ListeAttributs symptomes;
};

#endif // MALADIE_HPP
