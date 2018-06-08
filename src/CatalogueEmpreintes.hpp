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
    // La fonction récupère toutes les informations du fichier pour créer une nouvelle empreinte qui sera ajoutée dans
    // la liste empreinte
    // Au préalable, il faut IMPERATIVEMENT que l'utilisateur ait fait tourner la fonction chargerDefinitionAttribut
    // afin de connaitre le type de chaque attribut

    bool chargerDefinitionAttributs(const string& cheminFichier);
    // Mode d'emploi : récupère l'adresse du fichier de méta-donnée fourni par l'utilisateur
    // La fonction récupère le type et le nom de chaque attribut qui constitueront ensuite les empreintes que donnera cet utilisateur.
    // Chaque definition sera stocké dans la liste definitionAttributs 

    const ListeEmpreintes& getEmpreintes() const;
    // Mode d'emploi : renvoie la liste empreintes

    const ListeDefinitionAttributs& getDefinitionAttribut() const;
    // Mode d'emploi : renvoie la liste des definitions des attributs

    void setDefinitionAttribut(ListeDefinitionAttributs liste);
    // Mode d'emploi : prend en paramètre une ListeDefinitionAttributs
    // la liste en question est stockée dans definitionAttributs

    string toString() const;
    // Mode d'emploi : renvoie un string décrivant l'ensemble des empreintes stockées dans le catalogue

private:
    void ajouterUneDefinitionAttribut(const string& attribut, const string& type);
    // Mode d'emploi : permet d'ajouter une nouvelle definition d'attributs dans definitionAttributs
    // à partir du nom (attribut) et du type (type) trouvés dans le fichier texte de l'utilisateur 

    int indexAttribut(const string& attribut);
    // Mode d'emploi : prend en paramètre le nom de l'attribut correspondant à la valeur dans le fichier empreinte
    // renvoie l'index correspondant à la position de l'attribut rechercher dans definitionAttributs

    ListeEmpreintes empreintes;
    ListeDefinitionAttributs definitionAttributs;
    bool idDef  = true;
};

#endif // CATALOGUEEMPREINTES_HPP
