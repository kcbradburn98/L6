FLAGS = -std=c++11 -g -Wall
CXX = g++
CPP_SRCS = $(wildcard *.cpp)
OBJ_SRCS = $(CPP_SRCS:.cpp=.o)

heap: $(OBJ_SRCS)
	$(CXX) $(FLAGS) -o $@ $(OBJ_SRCS)

%.o: %.cpp %.h
	$(CXX) $(FLAGS) -c -o $@ $<

clean:
	rm *.o heap
