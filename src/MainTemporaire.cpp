#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "CatalogueEmpreintes.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
<<<<<<< HEAD
#include "Test.hpp"
=======
#include "KNN.hpp"
#include "Resultat.hpp"
>>>>>>> 567b84bfe25e05b0afe109e9a5b7ea5160bb0e80

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
<<<<<<< HEAD
		
		cout << "Le systeme a ete initialise avec succes" << endl;
		
		if(argc>=2 && strcmp("test", argv[1])==0)
=======
		else if(strcmp("empreinte", argv[2])==0)
>>>>>>> 567b84bfe25e05b0afe109e9a5b7ea5160bb0e80
		{
			if(strcmp("definition", argv[2])==0)
			{
				ListeDefinitionAttributs definitionAttributs = catalogueEmpreintes.getDefinitionAttribut();
				for(int i = 0; i<definitionAttributs.size(); i++)
				{
					cout << definitionAttributs[i]->toString() << endl;
				}
			}
			/**else if(strcmp("empreinte", argv[2])==0)
			{
				AttributDouble * attDouble;
				AttributString * attString;

				vector<DefinitionAttributs> definitionAttributs = catalogueEmpreintes.getDefinitionAttributs();
				CatalogueEmpreintes::ListeEmpreintes listeEmpreintes = catalogueEmpreintes.getEmpreintes();

				for(CatalogueEmpreintes::ListeEmpreintes::iterator it=listeEmpreintes.begin(); it!=listeEmpreintes.end(); it++)
				{
					ListeAttributs listeAttributs = it->second.getAttributs();
					vector<DefinitionAttributs>::const_iterator attDef=definitionAttributs.begin();
					for(vector<Attribut*>::const_iterator attListe=listeAttributs.begin(); attListe!=listeAttributs.end() && attDef!=definitionAttributs.end(); attListe++, attDef++)
					{
						switch(attDef->getType())
						{
							case(ATTRIBUT_ID):
								attDouble = dynamic_cast<AttributDouble*> (*attListe);
								cout << "ID : " << attDouble->getValeur() << endl;
								break;
							case(ATTRIBUT_DOUBLE):
								attDouble = dynamic_cast<AttributDouble*> (*attListe);
								cout << attDef->getNom() << " : " << attDouble->getValeur() << endl;
								break;
							case(ATTRIBUT_STRING):
								attString = dynamic_cast<AttributString*> (*attListe);
								cout << attDef->getNom() << " : " << attString->getValeur() << endl;
								break;
						}
					}

					set<string> maladies = it->second.getMaladies();
					cout << "Maladie(s) :";
					for(set<string>::iterator mal=maladies.begin(); mal!=maladies.end(); mal++)
					{
						cout<<" "<<*mal;
					}
					cout << endl << endl;
				}
<<<<<<< HEAD
			}*/
		}
=======
				cout << endl << endl;
			}
		}
		//tests knn1
		else if (strcmp("knn1", argv[2]) == 0)
		{
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
			for (Resultat r : res) {
				cout << r;
			}

		}

		//tests knn2
		else if (strcmp("knn2", argv[2]) == 0)
		{
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
			for (Resultat r : res) {
				cout << r;
			}

		}

		
>>>>>>> 567b84bfe25e05b0afe109e9a5b7ea5160bb0e80
	}
}