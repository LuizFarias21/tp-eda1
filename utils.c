#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar() {
    printf("\n> Pressione ENTER para continuar...");
    setbuf(stdin, NULL);
    getchar();
}

void linha_divisoria() { printf("+--------------------------------------+\n"); }

void exibir_cabecalho(const char *titulo) {
    printf("+======================================+\n");
    printf("| %-36s |\n", titulo);
    printf("+======================================+\n");
}
