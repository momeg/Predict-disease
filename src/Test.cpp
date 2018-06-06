#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CatalogueEmpreintes.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "DefinitionAttributDouble.hpp"
#include "DefinitionAttributString.hpp"
#include "DefinitionAttributId.hpp"
#include "Test.hpp"
#include "KNN.hpp"

using namespace std;

Test::Test()
{

}


void Test::faireTest(string test)
{
	initialisation();
    if(test == "definition")
        testDefinitionAttribut();
    else if(test == "empreintes")
        testCatalogueEmpreintes();
	else if (test == "bornes")
		testBornes();
	else if (test == "knn1")
		testKNN1();
	else if (test == "knn2")
		testKNN2();
}

void Test::initialisation()
{
	string cheminFichier;

	cout << "Veuillez initialiser le catalogue" << endl;

	cout << "Veuillez fournir le chemin du fichier contenant la definition des caracteristiques des empreintes" << endl;
	cin >> cheminFichier;

	while (!catalogueRef.chargerDefinitionAttributs(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	cheminFichierDefAttribut = cheminFichier;

	cout << "Les caracteristiques des empreintes ont bien ete initialisees" << endl;

	cout << "Veuillez fournir le chemin du fichier des empreintes de reference" << endl;
	cin >> cheminFichier;

	while (!catalogueRef.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	
	cout << "Le systeme a ete initialise avec succes" << endl;
}

void Test::testDefinitionAttribut()
{
    ListeDefinitionAttributs definitionAttributs = catalogueRef.getDefinitionAttribut();
    for(int i = 0; i<definitionAttributs.size(); i++)
    {
        cout << definitionAttributs[i]->toString() << endl;
    }
}

void Test::testCatalogueEmpreintes()
{
    cout << catalogueRef.toString() << endl;
}

void Test::testBornes()
{
	ListeDefinitionAttributs definitionAttributs = catalogueRef.getDefinitionAttribut();

	cout << endl;
    for(int i = 0; i<definitionAttributs.size(); i++)
    {
		if(definitionAttributs[i]->getType()==ATTRIBUT_DOUBLE)
		{
			cout << definitionAttributs[i] -> getNom() << " : ";
			cout << "max = " << dynamic_cast<const DefinitionAttributDouble*> ((const DefinitionAttribut*)definitionAttributs[i])->getMax();
			cout << ", min = " << dynamic_cast<const DefinitionAttributDouble*> ((const DefinitionAttribut*)definitionAttributs[i])->getMin() << endl;
		}
    }
}

void Test::testKNN1( )
{
	string cheminFichier;
	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
	catalogueEmpreintesAAnalyser.chargerDefinitionAttributs(cheminFichierDefAttribut);
	cout << "Veuillez fournir le chemin du fichier des empreintes a analyser" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintesAAnalyser.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	cout << "Le fichier a analyser a ete charge avec succes" << endl;
	KNN knn_model(1);
	vector<Resultat> res = knn_model.analyser(catalogueRef,catalogueEmpreintesAAnalyser);
	for (Resultat r : res)
	{
		cout << r;
	}
}

void Test::testKNN2()
{
	string cheminFichier;

	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
	catalogueEmpreintesAAnalyser.chargerDefinitionAttributs(cheminFichierDefAttribut);
	
	cout << "Veuillez fournir le chemin du fichier des empreintes a analyser" << endl;
	cin >> cheminFichier;
	
	cout<<cheminFichier;
	while (!catalogueEmpreintesAAnalyser.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	cout << "Le fichier a analyser a ete charge avec succes" << endl;
	KNN knn_model(3);
	vector<Resultat> res = knn_model.analyser(catalogueRef, catalogueEmpreintesAAnalyser);
	for (Resultat r : res)
	{
		cout << r;
	}
}

