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