#include <string>
#include <vector>
#include <utility>
using namespace std;
class Resultat
{
public:
	Resultat();
	~Resultat();
	void setId(unsigned int idEmp);
protected:
	unsigned int id;
	vector < pair <Maladie;double> > maladies;
};

