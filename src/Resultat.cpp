#include "Resultat.hpp"



Resultat::Resultat()
{
}

Resultat::Resultat(unsigned int idEmp , const vector < pair <string, double> >& m)
{
	id = idEmp;
	maladies = m;
}

void Resultat::setId(unsigned int  idEmp )
{
	id = idEmp;
}
unsigned int  Resultat::getId() {
	return id;
}

vector < pair <string, double> >  Resultat::getMaladies(){
	return maladies;
}

ostream& operator<<(ostream& os, const Resultat& res) {
	os << res.id;
	for (pair <string, double> p : res.maladies) {
		os <<";"<< p.first << ":" << p.second;
	}
	os << endl;
	return os;
}

Resultat::~Resultat()
{
}
