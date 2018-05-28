#ifndef TEST_HPP
#define TEST_HPP


#include "Empreinte.hpp"

#include <unordered_map>
#include<vector>

class Test
{
public:
    Test();

public:
    void faireTest(string test);

private:
    void initialisation();

    void testDefinitionAttribut();

    void testCatalogueEmpreintes();

    void testKNN1();

    void testKNN2();

protected:
    string cheminFichierDefAttribut;
    CatalogueEmpreintes catalogueRef;
    

};

#endif // TEST_HPP
