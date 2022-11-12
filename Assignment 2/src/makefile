CC = gcc
CFLAGS =  -Wall -Werror -ansi #-DDEBUG
LDFLAGS = -lm


program: prepare main.o menu.o huffman.o userInput.o encryption.o accountManagement.o session.o	
	$(CC) $(CFLAGS) out/main.o  out/menu.o out/huffman.o out/userInput.o out/encryption.o out/accountManagement.o out/session.o ${LDFLAGS} -o program 
prepare:
	mkdir -p out
	mkdir -p accounts
	mkdir -p data
main.o: main.c
	$(CC) $(CFLAGS) -o out/main.o -c main.c
	
menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -o out/menu.o -c menu.c
	
huffman.o: huffman.c huffman.h
	$(CC) $(CFLAGS) -o out/huffman.o -c huffman.c

userInput.o: userInput.c userInput.h
	$(CC) $(CFLAGS) -o out/userInput.o -c userInput.c

accountManagement.o: accountManagement.c accountManagement.h
	$(CC) $(CFLAGS) -o out/accountManagement.o -c accountManagement.c

encryption.o: encryption.c encryption.h
	$(CC) $(CFLAGS) -o out/encryption.o -c encryption.c

session.o: session.c session.h
	$(CC) $(CFLAGS) -o out/session.o -c session.c

clean:
	rm out/*.o

	


