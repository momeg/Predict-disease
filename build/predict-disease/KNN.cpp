#include "KNN.h"


KNN::KNN()
{
	k = 1;// l'algorithme fonctionne avec 1 voisin par defaut 
}

KNN::KNN(unsigned int nbVoisins)
{
	k = nbVoisins;
}

KNN::~KNN()
{
}

vector<Resultat> KNN::analyser(const CatalogueEmpreintes& reference, const CatalogueEmpreintes& aTraiter)
{

}

Resultat KNN::analyser(const CatalogueEmpreintes& reference, const Empreinte& aTraiter)
{

}

double KNN::calculerDistance(const Empreinte& empRef, const Empreinte& empAAnalyser) {

}
