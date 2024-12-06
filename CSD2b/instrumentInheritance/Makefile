CXX=g++
CXXFLAGS=-Wall -std=c++14
LDFLAGS=
SOURCE= main.o instrument.o strings.o percs.o keys.o

example: $(SOURCE)
	$(CXX) -o $@ $(SOURCE) $(LDFLAGS)

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<
	
clean:
	rm -f example *.o
