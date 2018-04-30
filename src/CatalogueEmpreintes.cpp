#include "CatalogueEmpreintes.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//----------------------------------------------------------------- PUBLIC

void CatalogueEmpreintes::chargerFichier(const string &cheminFichier)
{
    ifstream fichier;
    fichier.open(cheminFichier);
}

void CatalogueEmpreintes::enregistrerFichier(const string &cheminFichier)
{
}

void CatalogueEmpreintes::chargerDefinitionAttribut(const string &cheminFichier)
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

            if (info == "AttributeName"){
                while (getline(fichier, uneLigne)){
                    infosLigne.str(uneLigne);

                    getline(infosLigne, attribut, ';');
                    getline(infosLigne, type);

                    if (type == "ID"){
                        definitionAttributs.insert(make_pair(attribut,ATTRIBUT_ID));
                    }

                }
            }
            else{

            }
        }
        else
        {
            cerr << "Le document est vide";
        }
    }
    else
    {
        cerr << "Le fichier n'a pas été trouvé" << endl;
    }
}

CatalogueEmpreinte::ListeEmpreintes CatalogueEmpreintes::getEmpreintes()
{
    return empreintes;
}

//-------------------------------------------- Constructeurs - destructeur
CatalogueEmpreintes::CatalogueEmpreinte()
{
}

//----------------------------------------------------------------- PRIVE