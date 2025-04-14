PROGRAM = Subsequences
OBJECTS = Subsequences.o

CPPOPTIONS = -IStanfordCPPLib -fvisibility-inlines-hidden
LDOPTIONS = -L.
LIB = -lStanfordCPPLib

all: $(PROGRAM)

Subsequences: $(OBJECTS)
	g++ -o $(PROGRAM) $(LDOPTIONS) $(OBJECTS) $(LIB)

Subsequences.o: Subsequences.cpp Makefile libStanfordCPPLib.a
	g++ -c $(CPPOPTIONS) Subsequences.cpp

libStanfordCPPLib.a:
	@rm -f libStanfordCPPLib.a
	(cd StanfordCPPLib; make all)
	ln -s StanfordCPPLib/libStanfordCPPLib.a .


tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAM)

