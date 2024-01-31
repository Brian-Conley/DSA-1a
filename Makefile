# Build file for assignment 1a
# Wrote for Linux systems, I don't know if this Makefile works on Windows

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
