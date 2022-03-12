#include <stdio.h>  
#include <stdlib.h>

#define SUCESSO 1
#define FALHA -1

struct Nodo{  
    int chave;
    int dado;  
    struct Nodo *prox;  
};      
   
int tamanho;  
int key;
//Representa o primeiro e ultimo da lista simplesmente encadeada  
struct Nodo *prim, *ult = NULL;
   

// Função pra inverter a lista
void imprime_invertido(struct Nodo *prim){
    // caso base
    if(prim == NULL)
       return;
  
    imprime_invertido(prim->prox);

    // imprimir primeiro depois que tudo foi impresso
    printf("%d ", prim->dado);
}
   
 
void addInMid(int data){
    int i;

    //Cria novo Nodo/Celula 
    struct Nodo *novo = (struct Nodo*)malloc(sizeof(struct Nodo));

    novo->dado = data; 
    novo->chave = key;
    novo->prox = NULL;  
      
    //verifica se a lista está vazia 
    if(prim == NULL){  
        //Se a lista está vazia, primeiro e ultimo vão apontar para o novo Nodo/Celula 
        prim = novo;  
        ult = novo;  
    }  
    else{ 
        struct Nodo *temp, *atual;
        //Guarda a posição do 'meio' da lista 
        int cont = (tamanho % 2 == 0) ? (tamanho/2) : ((tamanho+1)/2);  

        temp = prim;  
        atual = NULL;  
   
        //Passa pela lista até que chegue no meio 
        for(i = 0; i<cont; i++){   
            atual = temp;  
            temp = temp->prox;  
        }

        atual->prox = novo;
        novo->prox = temp;  
    }

    tamanho++;  
    key++;
}  



//Remove a celula com a chave dada
void remove_por_chave(int chave){

   //Começa da primeira celula
   struct Nodo *atual = prim;
   struct Nodo *anterior = NULL;
	
   //Se a lista estiver vazia
   if(prim == NULL)
       printf("Lista vazia!\n");

   //Navega pela lista
   while(atual->dado != chave){

      //Se for o ultimo Nodo
      if(atual->prox == NULL)
          printf("Lista esta vazia!\n");
      else{
         anterior = atual;
         atual = anterior->prox;
      }
   }

   if(atual == prim)
      prim = prim->prox;
   else
      atual->prox = atual->prox;

   tamanho--;
}

      
int main(){  
    int valor, op, posicao;
    
    do{
        printf("1 - Inserir elemento na Lista\n2 - Remover elemento da Lista por chave\n3 - Imprimir Lista\n9 - Sair\n\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("Digite um valor a ser inserido: ");
                scanf("%d", &valor);
                addInMid(valor);
                printf("%d inserido com sucesso!\n\n", valor);
                break;
            case 2:
                printf("Digite a chave: ");
                scanf("%i", &posicao);
                remove_por_chave(posicao);
                break;
            case 3:
                printf("Lista no momento: ");
                imprime_invertido(prim);
                printf("\n");
                break;
            case 9:
                printf("FIM!\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while(op!=9);

    return 0;  
}