#ifndef CATALOGUEEMPREINTES_HPP
#define CATALOGUEEMPREINTES_HPP


#include "Empreinte.hpp"
#include "ListeDefinitionAttributs.hpp"

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
    // La fonction récupère toutes les informations du fichier pour créer une nouvelle empreinte qui sera ajouter dans
    // la liste empreinte
    // Au préalable, il faut IMPERATIVEMENT que l'utilisateur ait fait tourner la fonction chargerDefinitionAttribut
    // afin de connaitre le type de chaque attribut

    bool chargerDefinitionAttributs(const string& cheminFichier);
    // Mode d'emploi : récupère l'adresse du fichier de méta-donnée fourni par l'utilisateur
    // La fonction récupère le type de chaque attribut qui constitueront les empreintes que donnera cet utilisateur
    // puis les stocke dans definitionAttributs 

    ListeEmpreintes getEmpreintes() const;
    // Mode d'emploi : renvoie la liste empreintes

    ListeDefinitionAttributs getDefinitionAttribut() const;

private:
    void ajouterUneDefinitionAttribut(const string& attribut, const string& type);

    int indexAttribut(const string& attribut);

    ListeEmpreintes empreintes;
    ListeDefinitionAttributs definitionAttributs;
};

#endif // CATALOGUEEMPREINTES_HPP
