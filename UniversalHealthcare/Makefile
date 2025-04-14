PROGRAM = UniversalHealthcare
OBJECTS = UniversalHealthcare.o

CPPOPTIONS = -IStanfordCPPLib -fvisibility-inlines-hidden
LDOPTIONS = -L.
LIB = -lStanfordCPPLib

all: $(PROGRAM)

UniversalHealthcare: $(OBJECTS)
	g++ -o $(PROGRAM) $(LDOPTIONS) $(OBJECTS) $(LIB)

UniversalHealthcare.o: UniversalHealthcare.cpp Makefile libStanfordCPPLib.a
	g++ -c $(CPPOPTIONS) UniversalHealthcare.cpp

libStanfordCPPLib.a:
	@rm -f libStanfordCPPLib.a
	(cd StanfordCPPLib; make all)
	ln -s StanfordCPPLib/libStanfordCPPLib.a .


tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAM)

