PROGRAM = KarelGoesHome
OBJECTS = KarelGoesHome.o

CPPOPTIONS = -IStanfordCPPLib -fvisibility-inlines-hidden -O3
LDOPTIONS = -L.
LIB = -lStanfordCPPLib

all: $(PROGRAM)

KarelGoesHome: $(OBJECTS)
	g++ -o $(PROGRAM) $(LDOPTIONS) $(OBJECTS) $(LIB)

KarelGoesHome.o: KarelGoesHome.cpp Makefile libStanfordCPPLib.a
	g++ -c $(CPPOPTIONS) KarelGoesHome.cpp

libStanfordCPPLib.a:
	@rm -f libStanfordCPPLib.a
	(cd StanfordCPPLib; make all)
	ln -s StanfordCPPLib/libStanfordCPPLib.a .


tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAM)

