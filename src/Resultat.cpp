#include "Resultat.hpp"



Resultat::Resultat()
{
}

Resultat::Resultat(unsigned int idEmp , vector < pair <string, double> > m)
{
	id = idEmp;
	maladies = m;
}

void Resultat::setId(unsigned int  idEmp )
{
	id = idEmp;
}

Resultat::~Resultat()
{
}
