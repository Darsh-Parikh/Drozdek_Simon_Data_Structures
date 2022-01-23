
pf_finder.exe: prime_factors.c factorLists.o
	gcc -g -Wall -o pf_finder prime_factors.c factorLists.o

factorLists.o: factorLists.c factorLists.h
	gcc -g -Wall -c factorLists.c

clean:
	del *.o pf_finder.exe