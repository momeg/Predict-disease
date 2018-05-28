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

};

#endif // TEST_HPP
