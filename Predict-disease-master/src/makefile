EXE = Predict-disease
CLEAN = efface

INT = Attribut.hpp AttributDouble.hpp AttributString.hpp CatalogueEmpreintes.hpp CatalogueMaladies.hpp Empreinte.hpp Maladie.hpp Main.hpp DefinitionAttribut.hpp DefinitionAttributDouble.hpp DefinitionAttributString.hpp DefinitionAttributId.hpp Resultat.hpp Modele.hpp Test.hpp KNN.hpp
REAL = $(INT:.hpp=.cpp)
OBJ = $(REAL:.cpp=.o)

RM = rm
RMFLAGS = -f
LIBS = core
ECHO = echo
COMP = g++
COMPFLAGS = -g -ansi -pedantic -Wall -std=c++11
EDL = g++

.PHONY : $(CLEAN)

all : $(EXE)

$(EXE) : $(OBJ)
	$(ECHO) "EdL"
	$(EDL) -o $(EXE) $(OBJ) 

Attribut.o : Attribut.hpp

AttributDouble.o : Attribut.hpp AttributDouble.hpp

AttributString.o : Attribut.hpp AttributString.hpp

CatalogueEmpreintes.o : CatalogueEmpreintes.hpp DefinitionAttributId.hpp DefinitionAttributDouble.hpp DefinitionAttributString.hpp AttributDouble.hpp AttributString.hpp

CatalogueMaladies.o : CatalogueMaladies.hpp

Empreinte.o : Empreinte.hpp AttributDouble.hpp AttributString.hpp

DefinitionAttribut.o : DefinitionAttribut.hpp

DefinitionAttributDouble.o : DefinitionAttribut.hpp DefinitionAttributDouble.hpp

DefinitionAttributString.o : DefinitionAttribut.hpp DefinitionAttributString.hpp

DefinitionAttributId.o : DefinitionAttribut.hpp DefinitionAttributId.hpp

KNN.o : KNN.hpp Resultat.hpp Attribut.hpp Empreinte.hpp

Main.o : MainTemporaire.cpp CatalogueEmpreintes.hpp CatalogueMaladies.hpp Modele.hpp Maladie.hpp Test.hpp

Maladie.o : Maladie.hpp

Modele.o : Modele.hpp CatalogueEmpreintes.hpp

Resultat.o : Resultat.hpp

Test.o : Test.hpp CatalogueEmpreintes.hpp AttributDouble.hpp AttributString.hpp

%.o : %.cpp
	$(ECHO) "compil de <$*>"
	$(COMP) $(COMPFLAGS) -c $< -o $@
	
$(CLEAN) :
	$(ECHO) "Effacement"
	$(RM) $(RMFLAGS) $(EXE) $(OBJ) $(LIBS)