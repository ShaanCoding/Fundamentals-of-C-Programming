CC = gcc
CFLAGS = -Wall -Werror -ansi
LDFLAGS = -lm

program: prepare main.o userInput.o menu.o
	$(CC) $(CFLAGS) out/main.o out/userInput.o out/menu.o $(LDFLAGS) -o program 
prepare:
	mkdir -p out
main.o: main.c main.h
	$(CC) $(CFLAGS) -o out/main.o -c main.c
userInput.o: userInput.c userInput.h
	$(CC) $(CFLAGS) -o out/userInput.o -c userInput.c
menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -o out/menu.o -c menu.c
clean:
	rm out/*.o
