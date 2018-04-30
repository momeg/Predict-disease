#ifndef EMPREINTE_HPP
#define EMPREINTE_HPP

#include "Attribut.hpp"

#include <vector>
#include <set>

class Empreinte
{
public:
	typedef vector<Attribut*> ListeAttributs;

	typedef set<string> ListeMaladies;

public:
	Empreinte(int lId, const ListeMaladies& lesMaladies, const ListeAttributs& lesAttributs);

	Empreinte(const Empreinte& empreinte);

	~Empreinte();

public:
	Empreinte& operator=(const Empreinte& empreinte);

public:
	int getId() const;

	const Attribut* getAttribut(const string& nom) const;

private:
	int id;

	ListeAttributs attributs;

	ListeMaladies maladies;
};

#endif // EMPREINTE_HPP
