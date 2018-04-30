#include "Resultat.h"
#include <vector>
#include "Modele.h"
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
		double calculerDistance(const Empreinte& empRef , const Empreinte& empAAnalyser);
};

