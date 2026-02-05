#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    int cpf;
    char nome[100];
    char email[100];
    char telefone[20];
    char data_nascimento[12];
    struct cliente *prox;
} Cliente;

Cliente *criar_lista_cliente();
void inserir_cliente(Cliente *head, Cliente *novo);
int obter_cpf();
void cadastrar_cliente(Cliente *head);
void listar_clientes(Cliente *head);
Cliente *buscar_cliente(Cliente *head, int cpf);
void editar_cliente(Cliente *head);
void remover_cliente(Cliente *head);
void menu_cliente(Cliente *head);

#endif
