// 
// Fichier : Main.cpp
// Description : Point d'entree de l'application.
// Auteur : Mathilde Goigoux (mathilde.goigoux@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include "CatalogueEmpreintes.hpp"
#include "CatalogueMaladies.hpp"
#include "KNN.hpp"
#include "Maladie.hpp"
#include "Test.hpp"

#include <stdio.h>
#include <fstream>
#include <ctime>
//#include "Resultat.hpp"
using namespace std;

CatalogueEmpreintes catalogueEmpreintes;
CatalogueMaladies catalogueMaladies;
Modele * modele;

string pseudo;
ofstream historique;


void heureHistorique()
//Ajoute l'heure actuelle dans l'historique
{
	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	historique << now->tm_mday << "/" << now->tm_mon << "/" << now->tm_year + 1900 << " " << now->tm_hour << "h" << now->tm_min;
}

void authentification()
//récupère le pseudo de l'utilisateur (pour le log)
{
	cout << "Bonjour" << endl;
	cout << "Veuillez rentrer votre nom d'utilisateur" << endl;
	cin >> pseudo;
	historique << "Conn:" << pseudo << ":";
	heureHistorique();
}

void creerEmpreintesReferences()
// initialise les références à partir du fichier fourni
{
	catalogueEmpreintes = CatalogueEmpreintes();	//On (re)initialise le catalogue d'empreintes

	string cheminFichier;

	cout << "Vous avez choisi d'initialiser les empreintes de reference" << endl;

	cout << "Veuillez fournir le chemin du fichier contenant la definition des caracteristiques des empreintes" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerDefinitionAttributs(cheminFichier)) //tant que l'adresse n'est pas valide
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	cout << "Les caracteristiques des empreintes ont bien ete initialisees" << endl;

	cout << "Veuillez fournir le chemin du fichier des empreintes de reference" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerFichier(cheminFichier)) //tant que l'adresse n'est pas valide
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	catalogueMaladies.remplirCatalogue(catalogueEmpreintes);//A partir des empreintes de références, on remplit le catalogue des maladies
	cout << "Le systeme a ete initialise avec succes" << endl;

	historique << ",Entraînement:";	//on remplit l'historique
	heureHistorique();
	historique << ":" << cheminFichier;

}

void ajouterEmpreintesReferences()
// permets à l'utilisateur d'ajouter des empreintes de référence sans avoir à refaire l'initialisation des 5000 empreintes dans son intégralité
{
	string cheminFichier;

	cout << "Vous avez choisi d'ajouter des empreintes de reference" << endl;
	cout << "Veuillez fournir le chemin du fichier des empreintes de reference" << endl;
	cin >> cheminFichier;

	while (!catalogueEmpreintes.chargerFichier(cheminFichier))
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}

	catalogueMaladies.remplirCatalogue(catalogueEmpreintes);
	cout << "Les empreintes ont ete ajoutees avec succes" << endl;

}

void analyserEmpreintes()
// analyse les empreintes fournies par l'utilisateur et génère un fichier de sortie
{
	string cheminFichier;
	CatalogueEmpreintes aAnalyser = CatalogueEmpreintes();
	vector <Resultat> resultatsAnalyse;

	aAnalyser.setDefinitionAttribut(catalogueEmpreintes.getDefinitionAttribut());


	cout << "Vous avez choisi d'analyser des empreintes" << endl;
	cout << " Veuillez fournir le chemin d'acces du fichier contenant les empreintes a analyser" << endl;
	cin >> cheminFichier;

	while (!aAnalyser.chargerFichier(cheminFichier))//tant que l'adresse n'est pas valide
	{
		cout << "Le fichier demande n'a pas pu etre ouvert" << endl;
		cout << "Veuillez fournir un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	resultatsAnalyse = modele->analyserEmpreintes(catalogueMaladies, catalogueEmpreintes, aAnalyser);

	cout << "Analyse terminee. A quelle adresse generer le fichier de sortie ?" << endl;
	cin >> cheminFichier;

	ofstream fichier(cheminFichier, ios::trunc);

	while (!fichier)//tant que l'adresse de sortie n'est pas valide
	{
		cout << "Impossible d'ouvrir fichier demande, veuillez specifier un autre chemin d'acces" << endl;
		cin >> cheminFichier;
	}
	string nomFichierAnalyse = cheminFichier;

	vector<Resultat>::iterator it;
	for (it = resultatsAnalyse.begin(); it != resultatsAnalyse.end(); ++it)
	{
		fichier << it->getId() << ",";

		auto maladies = it->getMaladies();

		for (auto iu = maladies.begin(); iu != maladies.end(); ++iu) {
			fichier << iu->first << ":" << iu->second << ",";
		}
		fichier << endl;
	}

	fichier.close();

	historique << ",PredBatch:";	//on remplit l'historique
	heureHistorique();
	historique << ":" << nomFichierAnalyse << ":"<< resultatsAnalyse.size();
	cout << "Le fichier a ete genere avec succes" << endl;

}

void afficherMaladies()
// affiche les maladies prises en compte par le système
// demande à l'utilisateur s'il veut des détails sur l'une d'entre elle
{
	string nomMaladie;

	cout << "Vous avez choisi de consulter le liste des maladies prises en charge" << endl;
	catalogueMaladies.afficherGlobale();

	cout << "Si vous souhaitez retourner au menu principal, veuillez taper 1" << endl;
	cout << "Sinon, si vous souhaitez afficher les symptomes d'une maladie, veuillez taper son nom" << endl;
	cin >> nomMaladie;

	while (nomMaladie.compare("1") != 0)
	{
		catalogueMaladies.afficherParticulier(nomMaladie);

		cout << endl;
		cout << "Si vous souhaitez retourner au menu principal, veuillez taper 1" << endl;
		cout << "Sinon, si vous souhaitez afficher les symptomes d'une autre maladie, veuillez taper son nom" << endl;
		cin >> nomMaladie;
	}

}



int main(int argc, char *argv[])
{

	if (argc >= 2 && strcmp("test", argv[1]) == 0)
	{
		Test test;
		test.faireTest(argv[2]);
	}
	else
	{
		historique.open("log.txt", ios::app);

		modele = new KNN();

		string option = "init";

		authentification();

		creerEmpreintesReferences();

		while (option.compare("5") != 0) {

			cout << "Que voulez-vous faire ?" << endl;
			cout << "Reinitialiser les empreintes de reference: tapez 1" << endl;
			cout << "Ajouter des empreintes de reference: tapez 2" << endl;
			cout << "Analyser des empreintes: tapez 3" << endl;
			cout << "Afficher la liste des maladies traitees: tapez 4" << endl;
			cout << "Quitter l'application: tapez 5" << endl;

			cin >> option;

			if (option.compare("1") == 0)
			{
				creerEmpreintesReferences();
			}
			else if (option.compare("2") == 0)
			{
				ajouterEmpreintesReferences();
			}
			else if (option.compare("3") == 0)
			{
				analyserEmpreintes();
			}

			else if (option.compare("4") == 0)
			{
				afficherMaladies();
			}
			else if (option.compare("5") != 0)
			{
				cout << "Veuillez choisir l'une des options proposees" << endl;
			}

		}
		//le client se déconnecte

		historique << ",Deconn:";
		heureHistorique();
		historique << endl;
		historique.close();
		cout << "Au revoir" << endl;
		return 0;
	}
}