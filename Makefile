# Build file for assignment 1a

OBJ := ImplementationA.o ImplementationB.o
EXE := ImpA ImpB

.PHONY: all
all : $(EXE)

ImpA : ImplementationA.o
	g++ ImplementationA.o -o $@

ImpB : ImplementationB.o
	g++ ImplementationB.o -o $@

ImplementationA.o : ImplementationA.cpp
	g++ -c ImplementationA.cpp -o $@

ImplementationB.o : ImplementationB.cpp
	g++ -c ImplementationB.cpp -o $@

.PHONY: clean
clean :
	rm -f $(EXE) $(OBJ)
