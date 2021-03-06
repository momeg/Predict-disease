#ifndef CATALOGUEEMPREINTES_HPP
#define CATALOGUEEMPREINTES_HPP


#include "Empreinte.hpp"
#include "DefinitionAttribut.hpp"

#include <unordered_map>
#include<vector>

class CatalogueEmpreintes
{
public:
    typedef unordered_map <int, Empreinte> ListeEmpreintes;

public:
    CatalogueEmpreintes();

public:
    
    bool chargerFichier(const string& cheminFichier);
    // Mode d'emploi : récupère l'adresse du fichier que l'utilisateur souhaite charger
    // La fonction récupère toutes les informations du fichier pour créer une nouvelle empreinte qui sera ajoutee dans
    // la liste empreintes
    // Au préalable, il faut IMPERATIVEMENT que l'utilisateur ait fait tourner la fonction chargerDefinitionAttribut
    // afin de connaitre le type de chaque attribut

    bool chargerDefinitionAttributs(const string& cheminFichier);
    // Mode d'emploi : récupère l'adresse du fichier de méta-données fourni par l'utilisateur
    // La fonction récupère le type de chaque attribut qui constitueront les empreintes que donnera cet utilisateur
    // puis les stocke dans definitionAttributs 

    const ListeEmpreintes& getEmpreintes() const;
    // Mode d'emploi : renvoie la liste empreintes

    const ListeDefinitionAttributs& getDefinitionAttribut() const;

    void setDefinitionAttribut(ListeDefinitionAttributs liste);

    string toString() const;

private:
    void ajouterUneDefinitionAttribut(const string& attribut, const string& type);

    int indexAttribut(const string& attribut);

    ListeEmpreintes empreintes;
    ListeDefinitionAttributs definitionAttributs;
    bool idDef  = true;
};

#endif // CATALOGUEEMPREINTES_HPP
