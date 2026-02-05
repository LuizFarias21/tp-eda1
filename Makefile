CC := gcc
CFLAGS := -W -Wall -Wshadow -pedantic

all: OBJETOS
	$(CC) $(CFLAGS) main.c produto.o cliente.o carrinho.o utils.o -o sistema

OBJETOS:
	$(CC) $(CFLAGS) -c produto.c
	$(CC) $(CFLAGS) -c cliente.c
	$(CC) $(CFLAGS) -c carrinho.c
	$(CC) $(CFLAGS) -c utils.c

run:
	./sistema

.PHONY: clean
clean:

	rm -f *.o
	rm -f sistema
