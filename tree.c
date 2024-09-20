#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int entrada;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int entrada) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->entrada = entrada;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int entrada) {
    if (raiz == NULL) return criarNo(entrada);
    if (entrada < raiz->entrada) {
        raiz->esquerda = inserirNo(raiz->esquerda, entrada);
    } else if (entrada > raiz->entrada) {
        raiz->direita = inserirNo(raiz->direita, entrada);
    }
    return raiz;
}

void emOrdem(No* raiz) {
    if (raiz == NULL) return;
    emOrdem(raiz->esquerda);
    printf("%d ", raiz->entrada);
    emOrdem(raiz->direita);
}

int main() {
    No* raiz = NULL;
    
    raiz = inserirNo(raiz, 15);
    inserirNo(raiz, 11);
    inserirNo(raiz, 18);
    inserirNo(raiz, 8);
    inserirNo(raiz, 12);
    inserirNo(raiz, 40);
    inserirNo(raiz, 5);
    inserirNo(raiz, 9);
    inserirNo(raiz, 4);
    inserirNo(raiz, 15);
    inserirNo(raiz, 24);
    
    emOrdem(raiz);
}
