#include "Resultat.hpp"
#include <vector>
#include <unordered_map>
#include "Modele.hpp"
#include "Attribut.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "Empreinte.hpp"
#include "algorithm"
#include <cassert>

class KNN :public  Modele
{
	protected:
		unsigned int k;
	public:
		KNN();
		KNN(unsigned int nbVoisins);
		~KNN();
		vector<Resultat> analyser(const CatalogueEmpreintes& reference, const CatalogueEmpreintes& aTraiter);
		Resultat analyser(const CatalogueEmpreintes& reference, const Empreinte& aTraiter);
	private:
		double distanceEmp(const Empreinte& empRef , const Empreinte& empAAnalyser, const CatalogueEmpreintes& catalague);
		double distanceStr(const string& str1, const string& str2);
};

bool distComp(pair<double, set<string>> p1, pair<double, set<string>> p2);
