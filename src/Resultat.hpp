#ifndef RESULTAT_HPP
#define RESULTAT_HPP

#include <string>
#include <vector>
#include <utility>
#include <ostream>

using namespace std;

class Resultat
{
public:
	Resultat();

	Resultat(unsigned int idEmp, const vector<pair<string, double>>& m);

	~Resultat();

public:
	void setId(unsigned int idEmp);

	unsigned int getId() const;

	vector<pair<string, double>> getMaladies();

	friend ostream& operator<<(ostream& os, const Resultat& res);

protected:
	unsigned int id;

	vector<pair<string, double>> maladies;
};

#endif // RESULTAT_HPP
