CC = gcc
CCFLAGS = -g -Wall

palindrome: palindrome.c string_stacks.o
	$(CC) $(CCFLAGS) -o palindrome palindrome.c string_stacks.o

string_stacks.o: string_stacks.c string_stacks.h
	$(CC) $(CCFLAGS) -c string_stacks.c

clean:
	del *.o palindrome.exe