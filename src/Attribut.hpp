#ifndef ATTRIBUT_HPP
#define ATTRIBUT_HPP

#include "TypeAttribut.hpp"

#include <string>

using namespace std;

class Attribut
{
protected:
	Attribut(const string& leNom);

public:
	virtual TypeAttribut getType() const = 0;

public:
	const string& getNom() const;

private:
	string nom;
};

#endif // ATTRIBUT_HPP
