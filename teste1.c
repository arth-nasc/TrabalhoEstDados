#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int dado;
    struct node *prox;
};

struct descritor{
    struct node *i, *f;
    int n;
};

// Função para inserir um nó na lista ordenadamente
void inserirOrdenado(struct descritor *d, int valor) {
    struct node *novo = malloc(sizeof(struct node));
    novo->dado = valor;
    novo->prox = NULL;

    // Se a lista estiver vazia ou o valor for menor que o primeiro elemento
    if (d->i == NULL || valor < d->i->dado) {
        novo->prox = d->i;
        d->i = novo;
    } else {
        struct node *atual = d->i;
        // Encontra o ponto de inserção na lista
        while (atual->prox != NULL && atual->prox->dado < valor) {
            atual = atual->prox;
        }
        novo->prox = atual->prox;
        atual->prox = novo;
    }
    d->n++;
}

// Função para calcular o valor médio dos nós na lista
float calcularMedia(struct descritor *d) {
    struct node *temp = d->i;
    int soma = 0;
    while (temp != NULL) {
        soma += temp->dado;
        temp = temp->prox;
    }
    return (float)soma / d->n;
}

// Função para remover o primeiro nó com valor imediatamente superior ao valor médio
void removerSuperiorMedia(struct descritor *d, float media) {
    struct node *anterior = NULL;
    struct node *atual = d->i;
    while (atual != NULL && atual->dado <= media) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (anterior == NULL) {
            d->i = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        d->n--;
    }
}

int main(int argc, char *argv[]) {
    int i = 0, nos;
    struct node *p, *lista;
    printf("Quantos nos deseja inserir? ");
    scanf("%i", &nos);
    
    struct descritor *d;
    d = malloc(sizeof(struct descritor));
    d->i = NULL;
    d->f = NULL;
    d->n = 0;
    
    srand(time(NULL));
    
    do {
        p = malloc(sizeof(struct node));
        p->dado = rand() % 99;
        p->prox = lista;
        lista = p;
		
        // Inserir o elemento na lista ordenadamente
        inserirOrdenado(d, p->dado);
		
        i++;
        printf("%i ", p->dado);
    } while (i < nos);

    printf("\nLista ordenada:\n");
    // Imprimir a lista ordenada
    struct node *temp = d->i;
    while (temp != NULL) {
        printf("%i ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");

    // Calcular o valor médio dos nós na lista
    float media = calcularMedia(d);
    printf("Valor medio: %.2f\n", media);

    // Remover o primeiro nó com valor imediatamente superior ao valor médio
    removerSuperiorMedia(d, media);

    printf("Lista com descritor final:\n");
    // Imprimir a lista com descritor final
    temp = d->i;
    while (temp != NULL) {
        printf("%i ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");

    return 0;
}
