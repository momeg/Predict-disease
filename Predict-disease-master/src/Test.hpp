#ifndef TEST_HPP
#define TEST_HPP


#include "Empreinte.hpp"

#include <unordered_map>
#include<vector>

class Test
{
public:
    Test();

    void faireTest(string test);

private:
    void initialisation();

    void testDefinitionAttribut();

    void testCatalogueEmpreintes();

    void testBornes();

    void testKNN1();
    void testKNN2();
    void testKNN3();
    void testKNN4();
    void testKNN5();

protected:
    string cheminFichierDefAttribut;
    CatalogueEmpreintes catalogueRef;


};

#endif // TEST_HPP
