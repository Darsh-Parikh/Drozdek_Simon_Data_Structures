CC = gcc
CFLAGS = -g -Wall

experiments: listHidden.o listInfo.o experimentTest.o listReversing.o listSorting.o
	$(CC) $(CFLAGS) -o experiments listHidden.o listInfo.o experimentTest.o listReversing.o listSorting.o

clean:
	del /f *.o experiments.exe

experimentTest.o: experimentTest.c 
	$(CC) $(CFLAGS) -c experimentTest.c

listInfo.o: listInfo.c
	$(CC) $(CFLAGS) -c listInfo.c

listHidden.o: listHidden.c
	$(CC) $(CFLAGS) -c listHidden.c

# Instructions for other files
listReversing.o: listReversing.c
	$(CC) $(CFLAGS) -c listReversing.c

listSorting.o: listSorting.c
	$(CC) $(CFLAGS) -c listSorting.c