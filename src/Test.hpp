#ifndef TEST_HPP
#define TEST_HPP


#include "Empreinte.hpp"
#include "ListeDefinitionAttributs.hpp"

#include <unordered_map>
#include<vector>

class Test
{
public:
    Test();

public:
    static void faireTest(string test);

private:
    static void testDefinitionAttribut();

    static void testCatalogueEmpreintes();

    static void testKNN1();

    static void testKNN2();

};

#endif // TEST_HPP
