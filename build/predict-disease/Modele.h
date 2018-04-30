#include <vector>
#include "Resultat.h"
class Modele
{
	public:
		Modele();
		~Modele();
		virtual vector<Resultat> analyser(const CatalogueEmpreintes& reference, CatalogueEmpreintes& aTraiter);
};

