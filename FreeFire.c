// -------------------------------
// Bibliotecas
// -------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// -------------------------------
// CONSTANTES
// -------------------------------
#define MAX_ITENS 10
#define TAM_NOME 30
#define TAM_TIPO 20

// -------------------------------
// ESTRUTURA DE DADOS: ITEM
// -------------------------------
// Representa um objeto armazenado na mochila do jogador.
typedef struct {
    char nome[TAM_NOME];  // Nome do item (ex: Pistola, Kit Médico)
    char tipo[TAM_TIPO];  // Tipo do item (ex: arma, munição, cura)
    int quantidade;       // Quantidade do item
} Item;

// -------------------------------
// VARIÁVEIS GLOBAIS
// -------------------------------
Item mochila[MAX_ITENS];  // Vetor que armazena os itens
int qtdItens = 0;         // Contador de itens cadastrados

// -------------------------------
// FUNÇÕES
// -------------------------------

// Busca de item na mochila
void buscarItemVetor(){
    if (qtdItens == 0){
        printf("\nA mochila esta vazia!\n");
        return;
    }

    char nomeBusca[TAM_NOME];
    int encontrado = 0;

    printf("\n--- BUSCAR ITEM ---\n");
    printf("Digite o nome do item: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n--- Item Encontrado! ---\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\n❌ Item não encontrado na mochila.\n");
    }
}

// Cadastra um novo item na mochila
void inserirItem() {
    if (qtdItens >= MAX_ITENS) {
        printf("\n⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("\n--- Adicionar Novo Item ---\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);

    printf("Tipo do item (arma, munição, cura, etc): ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[qtdItens] = novo;
    qtdItens++;

    printf("\n✅ Item \"%s\" adicionado com sucesso!\n", mochila[qtdItens - 1].nome);
}

// Remove um item da mochila com base no nome
void removerItem() {
    if (qtdItens == 0) {
        printf("\n⚠️ Mochila vazia! Nenhum item para remover.\n");
        return;
    }

    char nomeBusca[TAM_NOME];
    printf("\n--- REMOVER ITEM ---\n");
    printf("Informe o nome do item a remover: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < qtdItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            encontrado = 1;
            // Desloca os itens seguintes uma posição para trás
            for (int j = i; j < qtdItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            qtdItens--;
            printf("\n🗑️ Item '%s' removido com sucesso!\n", nomeBusca);
            break;
        }
    }

    if (!encontrado)
        printf("\n❌ Item não encontrado na mochila.\n");
}

// Lista todos os itens da mochila
void listarItens() {
    if (qtdItens == 0) {
        printf("\nA mochila está vazia!\n");
        return;
    }

    printf("\n--- ITENS NA MOCHILA (%d/%d) ---\n", qtdItens, MAX_ITENS);
    printf("-------------------------------------------------\n");
    printf("%-20s | %-15s | %-10s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < qtdItens; i++) {
        printf("%-20s | %-15s | %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade);
    }

    printf("-------------------------------------------------\n");
}

// -----------------------------
// Exibe o menu principal
// -----------------------------
void menu() {
    int opcao;

    do {
        printf("\n=============================================================\n");
        printf("       🎒 MOCHILA DE SOBREVIVENCIA - CODIGO DA ILHA 🎮     \n");
        printf("=============================================================\n");
        printf("Itens na mochila: %d/%d\n", qtdItens, MAX_ITENS);
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item na mochila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItemVetor(); break;
            case 0: printf("\nSaindo da mochila... Até a próxima missão!\n"); break;
            default: printf("\n❌ Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

// -------------------------------
// FUNÇÃO PRINCIPAL
// -------------------------------
int main() {
    menu();
    return 0;
}