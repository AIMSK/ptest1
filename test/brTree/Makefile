CXX=g++
S_SRCS := $(wildcard ./*.cpp)
S_OBJS =  $(patsubst %cpp, %o, $(S_SRCS))
OUTPUT=test
OBJS += main.o
OBJS += brTreeFunc.o
DEFINES =
#DEBUG = -D DEBUG
LIBS=
INCLUDES=
FLAGS = 
#$(info $(S_SRCS))
#$(info $(S_OBJS))

debug: FLAGS += -D DEBUG
debug: $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(OUTPUT)
	@echo "---------------------------------------"

$(OUTPUT): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(OUTPUT)
	@echo "---------------------------------------"

%.o:%.cpp
	$(CXX) $(FLAGS) -c $< -o $@

.PHONY:print
print:
	@echo $(S_SRCS)
	@echo $(S_OBJS)

.PHONY:clean
clean:
	rm *.o
	rm $(OUTPUT)
