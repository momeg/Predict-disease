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
            while(getline(infosLigne, info, ';')){
                ordreAttributs.push_back(info);
            }

            int numeroAttribut;
            ListeAttributs * listeAttributs;
            int index;

            int id;
            bool idNonExistant;

            string maladie;
            bool malade;

            while(getline(fichier, uneLigne)){  //On lit une ligne
                listeAttributs = new ListeAttributs();
                numeroAttribut = 0;

                infosLigne.clear();
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
                        index = indexAttribut(ordreAttributs[numeroAttribut]);
                        if (definitionAttributs[index]->getType()==ATTRIBUT_DOUBLE){
                            double valeur = stod(info);
                            listeAttributs->ajouterAttribut(new AttributDouble(valeur));
                            ((DefinitionAttributDouble*) definitionAttributs[index])->setMin(valeur);
                            ((DefinitionAttributDouble*) definitionAttributs[index])->setMax(valeur);
                        }
                        else if (definitionAttributs[index]->getType()==ATTRIBUT_STRING){
                            listeAttributs->ajouterAttribut(new AttributString(info));
                        }
                        else if (definitionAttributs[index]->getType()==ATTRIBUT_ID){
                            id = stoi(info);
                            if(empreintes.find(id)!=empreintes.end()){
                                idNonExistant = false;
                            }
                        }
                    }
                    ++numeroAttribut;
                }

                if(idNonExistant){
                    empreintes.insert(make_pair(id,Empreinte(id, *listeAttributs)));
                }
                if(malade && (empreintes.find(id)!=empreintes.end())){
                    empreintes[id].ajouterMaladie(maladie);
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

            if (info == "AttributeName"){   //L'attribut est avant le type
                while (getline(fichier, uneLigne)){
                    infosLigne.clear();
                    infosLigne.str(uneLigne);

                    getline(infosLigne, attribut, ';');
                    getline(infosLigne, type);

                    ajouterUneDefinitionAttribut(attribut, type);
                }
            }
            else{                           //Le type est avant l'attribut
                while (getline(fichier, uneLigne)){

                    cout << uneLigne << endl;
                    infosLigne.clear();
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

CatalogueEmpreintes::ListeEmpreintes CatalogueEmpreintes::getEmpreintes() const
{
    return empreintes;
}

ListeDefinitionAttributs CatalogueEmpreintes::getDefinitionAttributs() const
{
    return definitionAttributs;
}

string CatalogueEmpreintes::toString() const 
{
    string s = "";
    set<string> listeMaladie;
    for(auto it = empreintes.begin(); it!=empreintes.end(); it++)
    {
        s += "ID : "+to_string(it->first)+"\n";
        for(int i = 0; i<definitionAttributs.size(); i++)
        {
            if(definitionAttributs[i]->getType()!=ATTRIBUT_ID)
            {
                s+= definitionAttributs[i]->getNom() + " : " + it->second.getAttributs()[definitionAttributs[i]->getIndice()]->toString() + "\n";
            }
        }
        s+="Maladie(s) :";

        set<string> listeMaladie = it->second.getMaladies();
        for(auto mal = listeMaladie.begin(); mal!=listeMaladie.end(); mal++)
        {
            s+=" "+ *mal;
        }
        s+="\n\n";
    }
    return s;
}

//-------------------------------------------- Constructeurs - destructeur
CatalogueEmpreintes::CatalogueEmpreintes()
{
}

//----------------------------------------------------------------- PRIVE

void CatalogueEmpreintes::ajouterUneDefinitionAttribut(const string& attribut, const string& type)
{
    if (type == "double"){
        definitionAttributs.ajouterDefinitionAttribut(new DefinitionAttributDouble(attribut));
    }
    else if (type == "string"){
        definitionAttributs.ajouterDefinitionAttribut(new DefinitionAttributString(attribut));
    }
    else if (type == "ID"){
        definitionAttributs.ajouterDefinitionAttribut(new DefinitionAttributId(attribut));
    }
}

int CatalogueEmpreintes::indexAttribut(const string& attribut)
{
    for(int i = 0; i<definitionAttributs.size(); i++)
    {
        if(definitionAttributs[i]->getNom().compare(attribut)==0)
        {
            return i;
        }
    }
    return NULL;
}