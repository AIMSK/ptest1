CXX=g++
FLAGS=
OUTPUT=test
OBJS += main.o
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

test: $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)

%.o:%.cpp
	$(CXX) $(FLAGS) -c $< -o $@


#brt:
#	$(CXX) -c brTreeFunc.cpp -o brTreeFunc.o

clean:
	rm *.o
	rm $(OUTPUT)
