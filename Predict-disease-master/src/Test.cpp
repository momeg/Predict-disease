#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

#include "CatalogueEmpreintes.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "DefinitionAttributDouble.hpp"
#include "DefinitionAttributString.hpp"
#include "DefinitionAttributId.hpp"
#include "Test.hpp"
#include "KNN.hpp"

using namespace std;
using namespace std::chrono;

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
	else if (test == "knn3")
		testKNN3();
	else if (test == "knn4")
		testKNN4();
	else if (test == "knn5")
		testKNN5();
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
	catalogueEmpreintesAAnalyser.setDefinitionAttribut(catalogueRef.getDefinitionAttribut());
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
	catalogueEmpreintesAAnalyser.setDefinitionAttribut(catalogueRef.getDefinitionAttribut());

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

//tester le temps d'execution de KNN
void Test::testKNN3()
{
	string cheminFichier;

	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
	catalogueEmpreintesAAnalyser.setDefinitionAttribut(catalogueRef.getDefinitionAttribut());

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
	auto start = high_resolution_clock::now();
	vector<Resultat> res = knn_model.analyser(catalogueRef, catalogueEmpreintesAAnalyser);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout <<"Temps d'execution de l'algorithme d'analyse KNN : "<<duration.count() << endl;

}

//tester la precision de l'algorithe KNN pour differents K (de 1 a 14 iclu)
void Test::testKNN4()
{
	string cheminFichier;

	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
	catalogueEmpreintesAAnalyser.setDefinitionAttribut(catalogueRef.getDefinitionAttribut());

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

	//charger le fichier des empreintes a analyser(avec labels)
	CatalogueEmpreintes catalogueEmpreintesAAnalyserLabeled = CatalogueEmpreintes();
	catalogueEmpreintesAAnalyserLabeled .setDefinitionAttribut(catalogueRef.getDefinitionAttribut());
	cout << "Veuillez fournir le chemin du fichier des empreintes a analyser(avec labels)" << endl;
	cin >> cheminFichier;

	cout<<cheminFichier;
	while (!catalogueEmpreintesAAnalyserLabeled.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	cout << "Le fichier a analyser avec labels a ete charge avec succes" << endl;
	for(int k = 1; k<15 ;k++){
		KNN knn_model(k);
		vector<Resultat> res = knn_model.analyser(catalogueRef, catalogueEmpreintesAAnalyser);
		double precision = knn_model.calculerPrecision(catalogueEmpreintesAAnalyserLabeled,catalogueEmpreintesAAnalyser);
		cout<<k<<","<<precision;
	}

}

//Mesurer le temps d'execution pour plusieurs valeurs de K
void Test::testKNN5()
{
	string cheminFichier;

	CatalogueEmpreintes catalogueEmpreintesAAnalyser = CatalogueEmpreintes();
	catalogueEmpreintesAAnalyser.setDefinitionAttribut(catalogueRef.getDefinitionAttribut());

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

	for(int k = 1; k<15 ;k++){
		KNN knn_model(k);
		auto start = high_resolution_clock::now();
		vector<Resultat> res = knn_model.analyser(catalogueRef, catalogueEmpreintesAAnalyser);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout <<k<<","<<duration.count() << endl;
	}
}
