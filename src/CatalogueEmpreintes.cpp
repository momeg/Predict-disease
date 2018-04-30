#include "CatalogueEmpreintes.hpp"
#include "AttributDouble"

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
            for(int i = 0; getline(infosLigne, info, ';'); i++){
                ordreAttributs[i] = info;
            }

            int numeroAttribut;
            ListeAttributs listeAttributs;

            int id;
            bool idNonExistant;

            string maladie;
            bool malade;

            while(getline(fichier, uneLigne)){  //On lit une ligne
                listeAttributs.vider();
                numeroAttribut = 0;
                infosLigne.str(uneLigne);
                idNonExistant = true;
                malade = false;

                while(getline(infosLigne, info, ';')){  //On lit chaque information de la ligne décrivant l'empreinte
                    if(ordreAttributs[numeroAttribut]=="Disease"){
                        malade = true;
                        maladie = info;
                    }
                    else if (idNonExistant){            //Si on retrouve deux fois la même id, c'est que l'on souhaite uniquement spécifier une autre maladie pour le client
                                                        // le reste n'a pas besoin d'être modifier
                        if (definitionAttributs[ordreAttributs[numeroAttribut]]==ATTRIBUT_DOUBLE){
                            listeAttributs.ajouterAttribut(new AttributDouble(ordreAttributs[numeroAttribut],stod(info)));
                        }
                        else if (definitionAttributs[ordreAttributs[numeroAttribut]]==ATTRIBUT_STRING){
                            listeAttributs.ajouterAttribut(new AttributDouble(ordreAttributs[numeroAttribut],info));
                        }
                        else if (definitionAttributs[ordreAttributs[numeroAttribut]]==ATTRIBUT_ID){
                            id = stoi(info);
                            if(empreintes.find(id)!=empreintes.end()){
                                idNonExistant = false;
                            }
                            else{
                                listeAttributs.ajouterAttribut(new AttributDouble(ordreAttributs[numeroAttribut],id));
                            }
                        }
                    }
                }

                if(idNonExistant){
                    empreintes.insert(make_pair(id,Empreinte(id, listeAttributs)));
                }
                if(malade){
                    empreintes[id].ajouterMaladie(maladie);
                }
            }
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

bool CatalogueEmpreintes::chargerDefinitionAttribut(const string &cheminFichier)
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

            if (info == "AttributeName"){   //L'attribut est avant le type
                while (getline(fichier, uneLigne)){
                    infosLigne.str(uneLigne);

                    getline(infosLigne, attribut, ';');
                    getline(infosLigne, type);

                    ajouterUneDefinitionAttribut(attribut, type);
                }
            }
            else{                           //Le type est avant l'attribut
                while (getline(fichier, uneLigne)){
                    infosLigne.str(uneLigne);

                    getline(infosLigne, type, ';');
                    getline(infosLigne, attribut);

                    ajouterUneDefinitionAttribut(attribut, type);
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

CatalogueEmpreintes::ListeEmpreintes CatalogueEmpreintes::getEmpreintes()
{
    return empreintes;
}

//-------------------------------------------- Constructeurs - destructeur
CatalogueEmpreintes::CatalogueEmpreintes()
{
}

//----------------------------------------------------------------- PRIVE

void CatalogueEmpreintes::ajouterUneDefinitionAttribut(const string& attribut, const string& type){

    if (type == "double"){
        definitionAttributs.insert(make_pair(attribut,ATTRIBUT_DOUBLE));
    }
    else if (type == "string"){
        definitionAttributs.insert(make_pair(attribut,ATTRIBUT_STRING));
    }
    else if (type == "ID"){
        definitionAttributs.insert(make_pair(attribut,ATTRIBUT_ID));
    }
}