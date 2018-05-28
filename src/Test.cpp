#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CatalogueEmpreintes.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "Test.hpp"
#include "KNN.hpp"

using namespace std;

void Test::faireTest(string test)
{
    if(test == "definition")
        testDefinitionAttribut();
    else if(test == "empreintes")
        testCatalogueEmpreintes();
	else if (test == "knn1")
		testKNN1();
	else if (test == "knn2")
		testKNN2();
}

void Test::testDefinitionAttribut()
{
    CatalogueEmpreintes catalogueEmpreintes = CatalogueEmpreintes();

	cout << "Veuillez initialiser le catalogue" << endl;

	string cheminFichier;

	cout << "Vous avez choisi d'initialiser les empreintes de reference" << endl;

	cout << "Veuillez fournir le chemin du fichier contenant la definition des caracteristiques des empreintes" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerDefinitionAttributs(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	cout << "Les caracteristiques des empreintes ont bien ete initialisees" << endl;

	cout << "Veuillez fournir le chemin du fichier des empreintes de reference" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	
	cout << "Le systeme a ete initialise avec succes" << endl;

    ListeDefinitionAttributs definitionAttributs = catalogueEmpreintes.getDefinitionAttribut();
    for(int i = 0; i<definitionAttributs.size(); i++)
    {
        cout << definitionAttributs[i]->toString() << endl;
    }
}

void Test::testCatalogueEmpreintes()
{
     CatalogueEmpreintes catalogueEmpreintes = CatalogueEmpreintes();

	cout << "Veuillez initialiser le catalogue" << endl;

	string cheminFichier;

	cout << "Vous avez choisi d'initialiser les empreintes de reference" << endl;

	cout << "Veuillez fournir le chemin du fichier contenant la definition des caracteristiques des empreintes" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerDefinitionAttributs(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	cout << "Les caracteristiques des empreintes ont bien ete initialisees" << endl;

	cout << "Veuillez fournir le chemin du fichier des empreintes de reference" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	
	cout << "Le systeme a ete initialise avec succes" << endl;

    cout << catalogueEmpreintes.toString() << endl;
}

void Test::testKNN1()
{
	CatalogueEmpreintes catalogueEmpreintes = CatalogueEmpreintes();
	string cheminFichier;

	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
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
	vector<Resultat> res = knn_model.analyser(catalogueEmpreintes,catalogueEmpreintesAAnalyser);
	for (Resultat r : res)
	{
		cout << r;
	}
}

void Test::testKNN2()
{
	CatalogueEmpreintes catalogueEmpreintes = CatalogueEmpreintes();
	string cheminFichier;

	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
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
	vector<Resultat> res = knn_model.analyser(catalogueEmpreintes, catalogueEmpreintesAAnalyser);
	for (Resultat r : res)
	{
		cout << r;
	}
}