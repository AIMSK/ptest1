CXX=g++
FLAGS=
S_SRCS := $(wildcard ./*.cpp)
S_OBJS =  $(patsubst %cpp, %o, $(S_SRCS))
OUTPUT=test
OBJS += main.o
OBJS += brTreeFunc.o
DEFINES=
LIBS=
INCLUDES=

#$(info $(S_SRCS))
#$(info $(S_OBJS))


test: $(OBJS)
	$(CXX) $(OBJS) -o $(OUTPUT)
	@echo "---------------------------------------"

%.o:%.cpp
	$(CXX) $(FLAGS) -c $< -o $@

print:
	@echo $(S_SRCS)
	@echo $(S_OBJS)

clean:
	rm *.o
	rm $(OUTPUT)
