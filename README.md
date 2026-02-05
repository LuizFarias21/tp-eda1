# Trabalho Prático - Estruturas de Dados 1

Este projeto consiste em um **Sistema de Gerenciamento de Vendas** desenvolvido em linguagem C. O sistema utiliza **Listas Encadeadas** para manipular dados de clientes, produtos e realizar operações de compra através de um carrinho virtual.

## 📋 Funcionalidades

O sistema é dividido em três módulos principais acessíveis através de um menu interativo:

### 1. Gerenciamento de Clientes

- **Cadastrar:** Inserção de novos clientes (CPF, Nome, Email, Telefone, Data de Nascimento).
- **Listar:** Exibição de todos os clientes cadastrados em formato tabular.
- **Buscar:** Localização de um cliente específico pelo CPF.
- **Editar:** Atualização dos dados cadastrais de um cliente.
- **Remover:** Exclusão de um cliente da lista.

### 2. Gerenciamento de Produtos

- **Cadastrar:** Inserção de novos produtos (Código, Nome, Preço, Quantidade em Estoque).
- **Listar:** Exibição do catálogo de produtos e seus respectivos estoques.
- **Buscar:** Consulta de detalhes de um produto pelo código.
- **Editar:** Alteração de preço, nome ou quantidade em estoque.
- **Remover:** Exclusão de um produto do sistema.

### 3. Modo Compra (Carrinho)

- **Adicionar Produto:** Seleção de produtos do estoque para o carrinho (valida a quantidade disponível).
- **Listar Carrinho:** Visualização dos itens atuais no carrinho de compras.
- **Retirar Produto:** Remoção ou diminuição da quantidade de um item no carrinho.
- **Finalizar Compra:** Conclusão do pedido, com baixa automática no estoque dos produtos vendidos.

## 🛠️ Tecnologias e Estruturas Utilizadas

- **Linguagem:** C
- **Estrutura de Dados:** Listas Simplesmente Encadeadas (Singly Linked Lists)
- **Alocação de Memória:** Dinâmica (`malloc`, `free`)

## 🚀 Como Compilar e Executar

Para compilar o projeto, você precisará de um compilador C (como o GCC). Abra o terminal na pasta do projeto e execute os comandos abaixo:

```bash
make
make run
```

## 👥 Integrantes do Grupo

- LUIZ CLAUDIO BARBOSA DE FARIAS - Matrícula: 232014487
- RICARDO EDUARDO DA SILVA LEAL - Matrícula: 242015405

