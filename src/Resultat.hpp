#include <string>
#include <vector>
#include <utility>

using namespace std;
class Resultat
{
public:
	Resultat();
	Resultat(unsigned int idEmp, vector < pair < string, double > > m);
	~Resultat();
	void setId(unsigned int idEmp);

protected:
	unsigned int id;
	vector < pair <string,double> > maladies;
};

