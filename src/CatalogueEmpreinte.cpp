#include "CatalogueEmpreinte.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//----------------------------------------------------------------- PUBLIC

void CatalogueEmpreinte::chargerFichier(const string &cheminFichier)
{
    ifstream fichier;
    fichier.open(cheminFichier);
}

void CatalogueEmpreinte::enregistrerFichier(const string &cheminFichier)
{
}

void CatalogueEmpreinte::chargerDefinitionAttribut(const string &cheminFichier)
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

CatalogueEmpreinte::ListeEmpreintes CatalogueEmpreinte::getEmpreintes()
{
    return empreintes;
}

//-------------------------------------------- Constructeurs - destructeur
CatalogueEmpreinte::CatalogueEmpreinte()
{
}

//----------------------------------------------------------------- PRIVE