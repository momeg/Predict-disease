#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CatalogueEmpreintes.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "KNN.hpp"
#include "Resultat.hpp"
#include "Test.hpp"

using namespace std;

int main (int argc, char *argv[])
{
	if(argc>=2 && strcmp("test", argv[1])==0)
	{
		Test::faireTest(argv[2]);
	}
	else
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
	}
}