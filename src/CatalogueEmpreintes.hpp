#ifndef CATALOGUEEMPREINTES_HPP
#define CATALOGUEEMPREINTES_HPP


#include "Attribut.hpp"
#include "Empreinte.hpp"

#include <unordered_map>

class CatalogueEmpreintes
{
public:
    typedef unordered_map <int, Empreinte> ListeEmpreintes;

    typedef unordered_map <string, TypeAttribut> ListeAttributs;

public:
    CatalogueEmpreintes();

public:
    void chargerFichier(const string& cheminFichier);

    void enregistrerFichier(const string& cheminFichier);

    void chargerDefinitionAttribut(const string& cheminFichier);

    ListeEmpreintes getEmpreintes();

private:
    ListeEmpreintes empreintes;
    ListeAttributs definitionAttributs;
};

#endif // CATALOGUEEMPREINTES_HPP
