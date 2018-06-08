#include <string>
#include <vector>
#include <utility>
#include <ostream>
#pragma once



using namespace std;
class Resultat
{
	
public:
	Resultat();
	Resultat(unsigned int idEmp, const vector < pair < string, double > >& m);
	~Resultat();
	void setId(unsigned int idEmp);
	unsigned int getId() const;
	vector < pair <string, double> > getMaladies();
	friend ostream& operator<<(ostream& os, const Resultat& res);

protected:
	unsigned int id;
	vector < pair <string,double> > maladies;
};

