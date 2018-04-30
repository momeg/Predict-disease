#ifndef ATTRIBUTSTRING_HPP
#define ATTRIBUTSTRING_HPP

#include "Attribut.hpp"

class AttributString : public Attribut
{
public:
	AttributString(const string& leNom, const string& laValeur);

public:
	virtual TypeAttribut getType() const;

public:
	const string& getValeur() const;

private:
	string valeur;
};

#endif // ATTRIBUTSTRING_HPP
