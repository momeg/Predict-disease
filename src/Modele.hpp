#include <vector>
#include "Resultat.hpp"
#include "CatalogueEmpreintes.hpp"
class Modele
{
	public:
		Modele();
		~Modele();
		virtual vector<Resultat> analyser(const CatalogueEmpreintes& reference, CatalogueEmpreintes& aTraiter);
};

