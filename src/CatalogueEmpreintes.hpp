#ifndef CATALOGUEEMPREINTES_HPP
#define CATALOGUEEMPREINTES_HPP


#include "Attribut.hpp"
#include "Empreinte.hpp"

#include <unordered_map>

class CatalogueEmpreintes
{
public:
    typedef unordered_map <int, Empreinte> ListeEmpreintes;

    typedef unordered_map <string, TypeAttribut> DefinitionAttributs;

public:
    CatalogueEmpreintes();

public:
    bool chargerFichier(const string& cheminFichier);

    bool chargerDefinitionAttribut(const string& cheminFichier);

    ListeEmpreintes getEmpreintes();

private:
    void ajouterUneDefinitionAttribut(const string& attribut, const string& type);

    ListeEmpreintes empreintes;
    DefinitionAttributs definitionAttributs;
};

#endif // CATALOGUEEMPREINTES_HPP
