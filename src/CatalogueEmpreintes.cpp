// 
// Fichier : CatalogueEmpreintes.cpp
// Description : Implementation de la classe CatalogueEmpreintes.
// Auteur : Martin Greco (martin.greco@insa-lyon.fr).
// Date de creation : 30 avril 2018
// Versions :
// - 1.0 : Creation de la classe.
// 
#include "CatalogueEmpreintes.hpp"
#include "AttributDouble.hpp"
#include "AttributString.hpp"
#include "DefinitionAttributId.hpp"
#include "DefinitionAttributString.hpp"
#include "DefinitionAttributDouble.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//----------------------------------------------------------------- PUBLIC

bool CatalogueEmpreintes::chargerFichier(const string &cheminFichier)
{
	ifstream fichier;
	fichier.open(cheminFichier);

	if (fichier)
	{ //Si on peut accéder au fichier indiqué
		string uneLigne;

		if (getline(fichier, uneLigne))
		{ //La ligne pour donner le format du document
			istringstream infosLigne;
			infosLigne.str(uneLigne);

			string info;
			vector<string> ordreAttributs;
			while (getline(infosLigne, info, ';')) {
				ordreAttributs.push_back(info);
			}

			int numeroAttribut;
			ListeAttributs * listeAttributs;
			int index;

			int id;
			bool idNonExistant;

			string maladie;
			bool malade;

			while (getline(fichier, uneLigne)) {  //On lit une ligne
				listeAttributs = new ListeAttributs();
				numeroAttribut = 0;

				infosLigne.clear();
				infosLigne.str(uneLigne);

				idNonExistant = true;
				malade = false;

				while (getline(infosLigne, info, ';')) {  //On lit chaque information de la ligne décrivant l'empreinte
					if (ordreAttributs[numeroAttribut] == "Disease") {
						malade = true;
						maladie = info;
					}
					else if (idNonExistant) {            //Si on retrouve deux fois la même id, c'est que l'on souhaite uniquement spécifier une autre maladie pour le client
														// le reste n'a pas besoin d'être modifier
						index = indexAttribut(ordreAttributs[numeroAttribut]);
						if (definitionAttributs[index]->getType() == ATTRIBUT_DOUBLE) {
							double valeur = stod(info);
							listeAttributs->push_back(new AttributDouble(valeur));
							dynamic_cast <DefinitionAttributDouble*> ((DefinitionAttribut*)definitionAttributs[index])->setMin(valeur);
							dynamic_cast <DefinitionAttributDouble*> ((DefinitionAttribut*)definitionAttributs[index])->setMax(valeur);
						}
						else if (definitionAttributs[index]->getType() == ATTRIBUT_STRING) {
							listeAttributs->push_back(new AttributString(info));
						}
						else if (definitionAttributs[index]->getType() == ATTRIBUT_ID) {
							id = stoi(info);
							if (empreintes.find(id) != empreintes.end()) {
								idNonExistant = false;
							}
						}
					}
					++numeroAttribut;
				}

				if (idNonExistant) {
					empreintes.insert(make_pair(id, Empreinte(id, *listeAttributs)));
				}
				if (malade && (empreintes.find(id) != empreintes.end())) {
					empreintes[id].ajouterMaladie(maladie);
				}
			}

			for(auto emp = empreintes.begin(); emp!=empreintes.end(); emp++) 	//On parcours la liste des empreintes créées pour placer les
																				//les valeurs normalisées
			{
				for(index = 0; index<definitionAttributs.size(); index ++)
				{
					if(definitionAttributs[index]->getType()==ATTRIBUT_DOUBLE)
					{
						double max = dynamic_cast<DefinitionAttributDouble*> ((DefinitionAttribut*)definitionAttributs[index])->getMax();
						double min = dynamic_cast<DefinitionAttributDouble*> ((DefinitionAttribut*)definitionAttributs[index])->getMin();
						AttributDouble* attDouble = dynamic_cast<AttributDouble*> (emp->second.getAttributs()[definitionAttributs[index]->getIndice()]->cloner());
						double valeur = attDouble->getValeur();
						double vNorm = (valeur-min)/(max-min);
						attDouble->setValeurNormalisee(vNorm);
						emp->second.setAttributIndice(attDouble, definitionAttributs[index]->getIndice());
					}
				}
			}
			return true;
		}
		else
		{
			cerr << "Le document est vide";
			return false;
		}
	}
	else
	{
		cerr << "Le fichier n'a pas été trouvé" << endl;
		return false;
	}
}

bool CatalogueEmpreintes::chargerDefinitionAttributs(const string &cheminFichier)
{
	ifstream fichier;
	fichier.open(cheminFichier);

	if (fichier)
	{ //Si on peut accéder au fichier indiqué
		string uneLigne;

		if (getline(fichier, uneLigne))
		{ //La ligne pour donner le format du document
			istringstream infosLigne;
			infosLigne.str(uneLigne);

			string info;
			string attribut;
			string type;

			getline(infosLigne, info, ';');

			if (info == "AttributeName") {   //L'attribut est avant le type
				while (getline(fichier, uneLigne)) {
					infosLigne.clear();
					infosLigne.str(uneLigne);

					getline(infosLigne, attribut, ';');
					getline(infosLigne, type);

					ajouterUneDefinitionAttribut(attribut, type);
				}
			}
			else if(info == "AttributeType") { 	//Le type est avant l'attribut
				while (getline(fichier, uneLigne)) {
					infosLigne.clear();
					infosLigne.str(uneLigne);

					getline(infosLigne, type, ';');
					getline(infosLigne, attribut);

					ajouterUneDefinitionAttribut(attribut, type);
				}
			}
			else
				return false;
			return true;
		}
		else
		{
			cerr << "Le document est vide";
			return false;
		}
	}
	else
	{
		cerr << "Le fichier n'a pas été trouvé" << endl;
		return false;
	}
}

const CatalogueEmpreintes::ListeEmpreintes& CatalogueEmpreintes::getEmpreintes() const
{
	return empreintes;
}

const ListeDefinitionAttributs& CatalogueEmpreintes::getDefinitionAttribut() const
{
	return definitionAttributs;
}

string CatalogueEmpreintes::toString() const
{
	string s;

	for(auto emp = empreintes.begin(); emp!=empreintes.end(); emp++)
	{
		for(int i=0; i<definitionAttributs.size(); i++)
		{
			s+= definitionAttributs[i]->getNom() + " : ";

			switch (definitionAttributs[i]->getType())
			{
				case(ATTRIBUT_DOUBLE):
					s+= to_string(dynamic_cast<const AttributDouble*> ((const Attribut*) emp->second.getAttributs()[definitionAttributs[i]->getIndice()])->getValeur());
					s+= ", valeur normalisee : " + to_string(dynamic_cast<const AttributDouble*> ((const Attribut*) emp->second.getAttributs()[definitionAttributs[i]->getIndice()])->getValeurNormalisee());
					break;
				case(ATTRIBUT_ID): 
					s += to_string(emp->second.getId());
					break;
				case(ATTRIBUT_STRING):
					s += dynamic_cast<const AttributString*> ((const Attribut*)emp->second.getAttributs()[definitionAttributs[i]->getIndice()])->getValeur();
					break;
			}
			s+="\n";
		}
		s+= "Maladie(s) :";
		set<string> maladies = emp->second.getMaladies();
		for(auto mal = maladies.begin(); mal!=maladies.end(); mal++)
		{
			s+= " "+*mal;
		}
		s+="\n\n";
	}
	return s;
}

void CatalogueEmpreintes::setDefinitionAttribut(ListeDefinitionAttributs liste)
{
	definitionAttributs = liste;
}

//-------------------------------------------- Constructeurs - destructeur
CatalogueEmpreintes::CatalogueEmpreintes()
{
}

//----------------------------------------------------------------- PRIVE

void CatalogueEmpreintes::ajouterUneDefinitionAttribut(const string& attribut, const string& type)
{
	if (type == "double") {
		definitionAttributs.push_back(new DefinitionAttributDouble(attribut));
	}
	else if (type == "string") {
		definitionAttributs.push_back(new DefinitionAttributString(attribut));
	}
	else if (type == "ID") {
		definitionAttributs.push_back(new DefinitionAttributId(attribut));
		idDef = true;
	}

	int taille = definitionAttributs.size();

	if(idDef)
	{
		definitionAttributs[taille-1]->setIndice(taille-2);
	}
	else
	{
		definitionAttributs[taille-1]->setIndice(taille-1);
	}
}

int CatalogueEmpreintes::indexAttribut(const string& attribut)
{
	for (size_t i = 0; i < definitionAttributs.size(); i++)
	{
		if (definitionAttributs[i]->getNom() == attribut)
		{
			return i;
		}
	}
	return 0;
}
