#include "cliente.h"
#include <stdlib.h>

Cliente *criarLista() {
    Cliente *head = malloc(sizeof(Cliente));
    head->prox = NULL;

    return head;
}
