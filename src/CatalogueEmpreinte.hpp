#ifndef CATALOGUEEMPREINTE_HPP
#define CATALOGUEEMPREINTE_HPP


#include "Attribut.hpp"
#include "Empreinte.hpp"

#include <unordered_map>

class CatalogueEmpreinte
{
public:
    typedef unordered_map <int, Empreinte> ListeEmpreintes;

    typedef unordered_map <string, TypeAttribut> ListeAttributs;

public:
    CatalogueEmpreinte();

public:
    void chargerFichier(const string& cheminFichier);

    void enregistrerFichier(const string& cheminFichier);

    void chargerDefinitionAttribut(const string& cheminFichier);

    ListeEmpreintes getEmpreintes();

private:
    ListeEmpreintes empreintes;
    ListeAttributs definitionAttributs;
};

#endif // CATALOGUEEMPREINTE_HPP
