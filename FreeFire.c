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