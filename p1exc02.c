#include<stdio.h>
#include<stdlib.h>

struct celula{
    int dado;
    struct celula *prox;
};

int cont;


struct celula *retorna_elementos_iguais(struct celula *a, struct celula *b){
    
     struct celula *iguais = (struct celula*) malloc(sizeof(struct celula));
    
    while (a != NULL && b != NULL){
        if (a->dado != b->dado)
            insert(&iguais, a->dado);
  
        a = a->prox;
        b = b->prox;
    }

    return iguais;
}

void insert(struct celula **prim, int dadonovo){

    struct celula *novo = (struct celula*) malloc(sizeof(struct celula));
  
    novo->dado = dadonovo;
    novo->prox = (*prim);
    (*prim) = novo;
}


int contador_iguais(struct celula *a, struct celula *b, int cont){
    while(a != NULL){
        struct celula *aux = b;
            while (aux != NULL){
                if (a->dado == b->dado)
                    cont++;
                if(a->dado == -1 && aux->dado == -1)
                    cont--;

                aux = aux->prox;
            }
           a = a->prox;
        }
    return cont;
}
  

int main(){
    struct celula *listaA = NULL;
    struct celula *listaB = NULL;
    int valor;
    
    while(1){
          scanf("%d", &valor);
          insert(&listaA, valor);

          if(valor == -1)
            break;
    }
    while(1){
          scanf("%d", &valor);
          insert(&listaB, valor);

          if(valor == -1)
            break;
    }
  
    int cont = 0;
    cont = contador_iguais(listaA, listaB, cont);
    printf("iguais %d\n", cont);
    struct Nodo *abc = retorna_elementos_iguais(listaA, listaB); 

    return 0;
}