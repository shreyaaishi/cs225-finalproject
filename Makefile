EXENAME = graph
OBJS = main.o
#OBJS = main.o readFromFile.o
CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

.PHONY: all test clean output.msg

all : $(EXENAME)

output_msg : ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

#readFromFile.o: main.cpp readFromFile.cpp $(CXX) $(CXXFLAGS) main.cpp readFromFile.cpp

readFromFile.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp 

# test: output_msg readFromFile.cpp
# 	$(LD)   readFromFile.cpp $(LDFLAGS) -o test

clean:
	-rm -f *.o $(EXENAME)