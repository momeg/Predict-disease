#ifndef ATTRIBUTDOUBLE_HPP
#define ATTRIBUTDOUBLE_HPP

#include "Attribut.hpp"

class AttributDouble : public Attribut
{
public:
	AttributDouble(const string& leNom, double laValeur);

public:
	virtual TypeAttribut getType() const;

public:
	double getValeur() const;

private:
	double valeur;
};

#endif // ATTRIBUTDOUBLE_HPP
