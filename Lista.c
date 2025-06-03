#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elemento {
    int valor;
    struct elemento *proximo; //ponteiro para o proximo no
} No;

typedef struct { // struct de controle
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

void inicializa(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

int inserirInicio(Lista *lista, int valor) {
    No *novo;

    if ((novo = (No*)malloc(sizeof(No))) == NULL) {
        return -1; // Falha ao alocar memória
    }

    novo->valor = valor;

    if (lista->inicio == NULL) { // Lista está vazia
        novo->proximo = NULL;
        lista->inicio = novo;
        lista->fim = novo;
    } else { // Inserir no início
        novo->proximo = lista->inicio;
        lista->inicio = novo;
    }

    lista->tamanho++; // Incrementa o tamanho corretamente
    return 0; // Sucesso
}

int inserirFim(Lista *lista, int valor) {
    No *novo;


    if((novo = (No*)malloc(sizeof(No))) == NULL) {
        return -1;
    }

    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
    lista->tamanho;
    return 0;
}

int inserirPosicao(Lista *lista, int valor, int posicao) {
	int i;
	
    if (posicao < 0 || posicao > lista->tamanho) {
        return -1; // Posição inválida
    }

    No *novo;
    if ((novo = (No*)malloc(sizeof(No))) == NULL) {
        return -1; // Falha ao alocar memória
    }
    novo->valor = valor;

    if (posicao == 0) { // Inserir no início
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        if (lista->fim == NULL) { // Caso a lista estivesse vazia
            lista->fim = novo;
        }
    } else { // Inserir no meio ou no final
        No *atual = lista->inicio;
        for (i = 0; i < posicao - 1; i++) {
            atual = atual->proximo;
        }
        novo->proximo = atual->proximo;
        atual->proximo = novo;

        if (novo->proximo == NULL) { // Atualizar o fim da lista
            lista->fim = novo;
        }
    }

    lista->tamanho++; // Incrementa o tamanho corretamente
    return 0; // Sucesso
}

void imprime(Lista *lista) {
    No *atual = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tamanho);
    while(atual != NULL) {
        printf("%d\n", atual->valor);
        atual = atual->proximo;
    }
}

int main() {
    Lista *lista;
    int aux, posicao;
    int op;

    if ((lista = (Lista*)malloc(sizeof(Lista))) == NULL) {
        return -1;
    }

    inicializa(lista);

    do {
        printf("\nMenu:\n");
        printf("1 - ADICIONAR UM ELEMENTO NO INICIO\n");
        printf("2 - ADICIONAR UM ELEMENTO NO MEIO\n");
        printf("3 - ADICIONAR UM ELEMENTO NO FINAL\n");
        printf("4 - REMOVER UM ELEMENTO NO INICIO\n");
        printf("5 - REMOVER UM ELEMENTO NO MEIO\n");
        printf("6 - REMOVER UM ELEMENTO NO FINAL\n");
        printf("7 - LISTAR ELEMENTOS\n");
        printf("8 - SAIR\n");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("\nVocê escolheu ADICIONAR UM ELEMENTO NO INICIO.\n");
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &aux);
                if (inserirInicio(lista, aux) == 0) {
                    printf("Valor inserido no início com sucesso!\n");
                } else {
                    printf("Erro ao inserir no início.\n");
                }
                break;

            case 2:
                printf("\nVocê escolheu ADICIONAR UM ELEMENTO NO MEIO.\n");
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &aux);
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                if (inserirPosicao(lista, aux, posicao) == 0) {
                    printf("Valor inserido na posição %d com sucesso!\n", posicao);
                } else {
                    printf("Erro ao inserir na posição %d.\n", posicao);
                }
                break;

            case 3:
                printf("\nVocê escolheu ADICIONAR UM ELEMENTO NO FINAL.\n");
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &aux);
                if (inserirFim(lista, aux) == 0) {
                    printf("Valor inserido no final com sucesso!\n");
                } else {
                    printf("Erro ao inserir no final.\n");
                }
                break;

            case 4:
                printf("\nVocê escolheu REMOVER UM ELEMENTO NO INICIO.\n");
                // Código para remover um elemento no início.
                break;

            case 5:
                printf("\nVocê escolheu REMOVER UM ELEMENTO NO MEIO.\n");
                // Código para remover um elemento no meio.
                break;

            case 6:
                printf("\nVocê escolheu REMOVER UM ELEMENTO NO FINAL.\n");
                // Código para remover um elemento no final.
                break;

            case 7:
                imprime(lista);
                break;

            case 8:
                printf("\nEncerrando o programa...\n");
                break;

            default:
                printf("\nOpção inválida! Por favor, tente novamente.\n");
                break;
        }
    } while (op != 8);

    return 0;
}
