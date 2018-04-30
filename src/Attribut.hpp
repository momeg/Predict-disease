#ifndef ATTRIBUT_HPP
#define ATTRIBUT_HPP

#include <string>

using namespace std;

class Attribut
{
protected:
	Attribut(const string& leNom);

private:
	string nom;
};

#endif // ATTRIBUT_HPP
