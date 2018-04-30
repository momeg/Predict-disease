#include "Resultat.h"
#include <vector>
#include "Modele.h"
#include "Attribut.hpp"
#include "Empreinte.hpp"
#include "algorithm"
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
		double distanceEmp(const Empreinte& empRef , const Empreinte& empAAnalyser);
		double distanceStr(const string& str1, const string& str2);
};

