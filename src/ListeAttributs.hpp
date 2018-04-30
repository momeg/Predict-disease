#ifndef LISTEATTRIBUTS_HPP
#define LISTEATTRIBUTS_HPP

#include "Attribut.hpp"

#include <vector>

class ListeAttributs
{
public:
	ListeAttributs();

	ListeAttributs(const ListeAttributs& liste);

	~ListeAttributs();

public:
	ListeAttributs& operator=(const ListeAttributs& liste);

public:
	const Attribut* getAttribut(const string& nom) const;

private:
	vector<Attribut*> attributs;
};

#endif // LISTEATTRIBUTS_HPP
