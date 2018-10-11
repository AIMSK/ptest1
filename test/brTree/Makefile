CXX=g++
FLAGS=
OUTPUT=test
OBJ=main.cpp
OBJS += $(OBJ)
OBJS += brTreeFunc.o
DEFINES=
LIBS=
INCLUDEs=


#test: dep1 dep2
#	@echo test
#	@echo test
#dep1: depdep1
#	@echo dep1
#dep2:
#	@echo dep2
#depdep1:
#	@echo depdep1

test: brt
	$(CXX) $(OBJS) -o $(OUTPUT)

brt:
	$(CXX) -c brTreeFunc.cpp -o brTreeFunc.o

clean:
	rm $(OUTPUT)
