#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct no { // estrutura de n´o para ´arvore bin´aria
    int info;
    struct no* esq;
    struct no* dir;
};

typedef struct no* arvore;

int vazia(arvore r){
    return (r == NULL);
}

void libera_arvore(arvore r) {
    if (!vazia(r)) {
        libera_arvore(r->esq);
        libera_arvore(r->dir);
        free(r);
    }
}

int eh_estritamente_binaria(arvore r) {
    if (vazia(r)) return 1; 
    if (r->esq == NULL && r->dir == NULL) return 1;
    if (r->esq != NULL && r->dir != NULL) return (eh_estritamente_binaria(r->esq) && eh_estritamente_binaria(r->dir)); 
    return 0; 
}

int altura(arvore r) {
  if (vazia(r)) return 0;
  else {
    int esq = altura(r->esq);
    int dir = altura(r->dir);
    if (esq > dir) return esq + 1;
    else return dir + 1;
  }
}
int num_nos(arvore r) {
  if (vazia(r)) return 0;
  return num_nos(r->esq) + 1 + num_nos(r->dir);
}

int cheia(arvore r) {
  if (vazia(r)) return 1;
  int h = altura(r);
  int n = num_nos(r);
  return (n == ((pow(2, h)) - 1));
}

int soma(arvore r) {
    if (vazia(r)) return 0;
    else return soma(r->esq) + soma(r->dir) + r->info;
}

int maximo(arvore r){
    while(r->dir != NULL) r = r->dir;
    return r->info;
}

int minimo(arvore r){
    while(r->esq != NULL) r = r->esq;
    return r->info;
}

arvore insere_arvore_binaria(arvore r, int x){
    if(vazia(r)) {
        r = (struct no*) malloc(sizeof(struct no));
        r->info = x;
        r->esq = NULL;
        r->dir = NULL;
    }
    else if(x < r->info)
    r->esq = insere_arvore_binaria(r->esq, x);
    
    else // x >= r->info
    r->dir = insere_arvore_binaria(r->dir, x);
    
    return r;
}
arvore remove_arvore_binaria(arvore r, int x){
    if(vazia(r)) return NULL;
    if(x < r->info) r->esq = remove_arvore_binaria(r->esq, x);
    else if(x > r->info) r->dir = remove_arvore_binaria(r->dir, x);
    else{ // x == r->info}
        if(r->esq == NULL && r->dir == NULL) { // ´e n´o folha
            free(r);
            r = NULL;
        }
        else if(r->esq == NULL) { // s´o tem filho da direita
            r->info = minimo(r->dir);
            r->dir = remove_arvore_binaria(r->dir,r->info);
        }
        else { // tem 2 filhos ou s´o o da esquerda
            r->info = maximo(r->esq);
            r->esq = remove_arvore_binaria(r->esq,r->info);
        }
    }
return r;
}

int contamaiorin_ordem(arvore r, int x){
    int c = 0;
    if(!vazia(r)){
        if(r->info > x){
            c = r->info;
        }
        c+= contamaiorin_ordem(r->esq, x);
        c+= contamaiorin_ordem(r->dir, x);
    }
    return c;
}

int contapares(arvore r){
    int c = 0;
    if(!vazia(r)){
        c+= contapares(r->esq);
        if(r->info % 2 == 0){
            c++;
        }
        c+= contapares(r->dir);
    }
    return c;
}
void in_ordem(arvore r){
    if(!vazia(r)){
        in_ordem(r->esq);
        printf("%d ", r->info);
        in_ordem(r->dir);
    }
}

void pre_ordem(arvore r){
    if(!vazia(r)) {
    printf("%d ", r->info);
    pre_ordem(r->esq);
    pre_ordem(r->dir);
    }
}

void pos_ordem(arvore r){
    if(!vazia(r)) {
    pos_ordem(r->esq);
    pos_ordem(r->dir);
    printf("%d ", r->info);
    }
}
void imprimir_intervalo(arvore r, int a, int b) {
    if (!vazia(r)){
        if (r->info > b) imprimir_intervalo(r->esq, a, b);
        if (r->info >= a && r->info <= b) {
            imprimir_intervalo(r->esq, a, b);
            printf("%d ", r->info);
            imprimir_intervalo(r->dir, a, b);
        }
        if (r->info < a) imprimir_intervalo(r->dir, a, b);
    }
}

int chave_seguinte(arvore r, int x) {
    if (vazia(r)) return -1;
    if (r->info == x) {
        arvore aux = r->dir;
        if (vazia(aux)) return -1;
        while (!vazia(aux->esq)) {
            aux = aux->esq;
        }
        return aux->info;
    }
    if (r->info > x) {
        int res = chave_seguinte(r->esq, x);
        if (res == -1) return r->info;
        else return res;
    }
    if (r->info < x) return chave_seguinte(r->dir, x);
    
}

int chave_anterior(arvore r, int x) {
    if (vazia(r)) return -1;
    if (r->info == x) {
        arvore aux = r->esq;
        if (vazia(aux)) return -1;
        while (!vazia(aux->dir)) {
            aux = aux->dir;
        }
        return aux->info;
    }
    if (r->info < x) {
        int res = chave_anterior(r->dir, x);
        if (res == -1) return r->info;
        else return res;
    }
    if (r->info > x) return chave_anterior(r->esq, x);
    
}

int nos_filho_unico(arvore r) {
    if (vazia(r)) return 0;
    
    if ((vazia(r->esq) && !vazia(r->dir)) || (!vazia(r->esq) && vazia(r->dir))) {
        return 1 + nos_filho_unico(r->esq) + nos_filho_unico(r->dir);
    }

    else return nos_filho_unico(r->esq) + nos_filho_unico(r->dir);

}

int nos_internos(arvore r) {
    if (vazia(r)) return 0;
    if (vazia(r->esq) && vazia(r->dir)) return 0;
    else {
        return 1 + nos_internos(r->esq) + nos_internos(r->dir);
    }
}

int qde_folhas(arvore r) {
    if (vazia(r)) return 0;
    if (vazia(r->esq) && vazia(r->dir)) return 1;
    else {
        return qde_folhas(r->esq) + qde_folhas(r->dir);
    }
}

int e_busca(arvore r) {
    if (vazia(r)) return 1;
    
    if (!vazia(r->esq)) {
        if (r->esq->info >= r->info || !e_busca(r->esq)) return 0;
    }

    if (!vazia(r->dir)) {
        if (r->dir->info <= r->info || !e_busca(r->dir)) return 0;
    }

    return 1;
}

void espelho(arvore r) {
    if (!vazia(r)){
        arvore aux = r->esq;
        r->esq = r->dir;
        r->dir = aux;
        espelho(r->esq);
        espelho(r->dir);
    }
}

int soma_intervalo(arvore r, int a, int b) {
    if (vazia(r)) return 0;
    if (r->info >= a && r->info <= b) return r->info + soma_intervalo(r->esq, a, b) + soma_intervalo(r->dir, a, b);
    else if (r->info < a) return soma_intervalo(r->dir, a, b);
    return soma_intervalo(r->esq, a, b);
}

int main(){
    arvore l1 = NULL;
    l1 = insere_arvore_binaria(l1, 10);
    l1 = insere_arvore_binaria(l1, 7);
    l1 = insere_arvore_binaria(l1, 15);
    l1 = insere_arvore_binaria(l1, 14);
    l1 = insere_arvore_binaria(l1, 2);
    l1 = insere_arvore_binaria(l1, 26);
    l1 = insere_arvore_binaria(l1, 8);
    l1 = insere_arvore_binaria(l1, 10);
    
    printf("Arvore binaria: ");
    in_ordem(l1);
    printf("\n");
    printf("Soma: %d\n", soma(l1));
    printf("\nARVORE POS REMOCÃO:\n\n");
    remove_arvore_binaria(l1, 1);
    printf("Arvore binaria in_ordem: ");
    in_ordem(l1);
    printf("\n");
    printf("Arvore binaria pre_ordem: ");
    pre_ordem(l1);
    printf("\n");
    printf("Arvore binaria pos_ordem: ");
    pos_ordem(l1);
    printf("\n");
    printf("Altura: %d\n", altura(l1));
    printf("Soma: %d\n", soma(l1));
    printf("é cheia: %d\n", cheia(l1));
    printf("é eh_estritamente_binaria: %d\n", eh_estritamente_binaria(l1));
    printf("num nos: %d\n", num_nos(l1));
    printf("maior que 25: %d\n", contamaiorin_ordem(l1, 25));
    printf("num pares: %d\n", contapares(l1));
    printf("intervalo a b: "); imprimir_intervalo(l1, 6, 27);
    printf("\n");
    printf("chave seguinte: %d\n", chave_seguinte(l1, 10));
    printf("chave anterior: %d\n", chave_anterior(l1, 10));
    printf("qde nos filho unico: %d\n", nos_filho_unico(l1));
    printf("qde nos internos: %d\n", nos_internos(l1));
    printf("qde folhas: %d\n", qde_folhas(l1));
    printf("é arvore de busca: %d\n", e_busca(l1));
    espelho(l1);
    printf("Arvore binaria espelhada: ");
    in_ordem(l1);
    printf("\n");
    printf("Soma intervalo: %d\n", soma_intervalo(l1, 10, 25));
    libera_arvore(l1);
    l1 = NULL;

    return 0;
}


