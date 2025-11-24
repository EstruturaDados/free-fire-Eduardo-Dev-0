#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR_LEN 30
#define TAM_MAX 20

typedef struct {
    char nome [MAX_STR_LEN];
    char tipo [TAM_MAX];
    int quantidade;
} ListaEstatica;

void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);

typedef struct No {
    char* dado;
    struct No *proximo;
} No;



int main() {
    int opcao;
    do{
        printf("\n--- INVENTARIO DO JOGADOR (TEXTO) ---\n");
        printf("1. Adicionar item\n");
        printf("2. listar itens do jogador\n");
        printf("3. remover itens do jogador\n");
        printf("0. Sair do Programa\n");
        printf("Esolha Uma opcao\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirListaEstatica;
                break;
            case 2:
                listarListaEstatica;
            case 3:
                removerListaEstatica;
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("opcao Invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}

void inicializarListaEstatica(ListaEstatica *lista) {
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto) {
    if (lista->quantidade == TAM_MAX) {
        printf("Erro: Lista Cheia! Nao e possivel inserir.\n");
        return;
    }

    strcpy(lista->nome[lista->quantidade], texto);
    lista->quantidade++;
    printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto) {
    int i, pos = -1;
    for (i = 0; i < lista->quantidade; i++) {
        if (strcmp(lista->nome[i], texto) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    for(i = pos; i < lista->quantidade - 1; i++) {
        strcpy(lista->nome[i], lista->nome[i + 1]);
    }

    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista) {
    if (lista->quantidade == 0) {
        printf ("A Lista Estatica Esta Vazia.\n");
        return;
    }
    printf("itens da lista Estatica: [ ");
    for (int i = 0; i < lista->quantidade; i++) {
        printf("\"%s\" ", lista->nome[i]);
    }
    printf("]\n");
}