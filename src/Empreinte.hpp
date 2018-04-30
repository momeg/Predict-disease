#ifndef EMPREINTE_HPP
#define EMPREINTE_HPP

#include "ListeAttributs.hpp"

#include <set>

class Empreinte
{
public:
	typedef set<string> ListeMaladies;

public:
	Empreinte(int lId, const ListeMaladies& lesMaladies, const ListeAttributs& lesAttributs);

public:
	int getId() const;

	const ListeAttributs& getAttributs() const;

	const ListeMaladies& getMaladies() const;

private:
	int id;

	ListeAttributs attributs;

	ListeMaladies maladies;
};

#endif // EMPREINTE_HPP
