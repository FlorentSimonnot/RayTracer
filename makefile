#
# Les variables d'environnement libG3X, incG3X
# sont definies dans le fichier ~/.bashrc par le script ../install.sh
#
#compilateur
CC = g++

CCEXT=
ifeq ($(CC),g++) #en mode debug
  CCEXT=++
endif

#compil en mode 'debug' ou optmisée (-O2)
DBG = no

ifeq ($(DBG),yes) #en mode debug
  CFLAGS = -g -Wpointer-arith -Wall -ansi
else               #en mode normal
  CFLAGS = -O2 -ansi
endif

# assemblage des infos de lib. et inc.
#lib =   $(libG3X)$(CCEXT)

# fichiers *.c locaux
src = src/
# fichiers *.h locaux et lib.
#inc = -I./include $(incG3X)
inc = -I.include/

exec = geometry 

# Cylinder.cpp Objet.cpp Point.cpp Rectangle.cpp Vector.cpp geometry.cpp ParentPointVector.cpp Ray.cpp Sphere.cpp Triangle.cpp Parser.cpp
SRC = Point.cpp Vector.cpp geometry.cpp ParentPointVector.cpp Ray.cpp Objet.cpp Sphere.cpp

OBJ = $(SRC:%.cpp=%.o)

all : $(exec) clean

# règle générique de création de xxx.o à partir de src/xxx.c
%.o : $(src)%.cpp
	@echo "module $@"
	@$(CC) $(CFLAGS) $(inc) -c $< -o $@
	@echo "------------------------"

	
$(exec): $(OBJ)
		$(CC) -o $@ $(OBJ)	
#$(exec): $(OBJ)
#		$(CC) -o $@ $(OBJ) $(lib)			

.PHONY : clean cleanall ?

# informations sur les paramètres de compilation
? :
	@echo "---------compilation informations----------"
	@echo "  processor      : $(PROCBIT)"
	@echo "  compiler       : $(CC)"
	@echo "  options        : $(CFLAGS)"
	@echo "  lib g3x/OpenGl : $(lib)"
	@echo "  headers        : $(incG3X)"
clean :
	@rm -f *.o
cleanall :
	@rm -f *.o $(exec) *~ */*~

