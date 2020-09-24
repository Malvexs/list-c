#include <stdio.h>
#include <stdlib.h>

struct elemento{
    void* tipo;
    struct elemento *newelemento;
};

struct lista{
    struct elemento *inicio;
    struct elemento *fim;
};

void inicializa_lista(struct lista *plista);
void inserir_elemento(struct lista *plista, void *value);
void remover_elemento(struct lista *plista, void *tormv);


int main(){

    struct lista lista_;           // criando lista
    inicializa_lista(&lista_);     //inicializa 

    inserir_elemento(&lista_, 15);  // add elementos
    inserir_elemento(&lista_, 16);
    inserir_elemento(&lista_, 17);
    inserir_elemento(&lista_, 18);
    inserir_elemento(&lista_, 19);
    inserir_elemento(&lista_, 20);

    remover_elemento(&lista_, 18); // remove elementos
    remover_elemento(&lista_, 16);

    struct elemento *iterator = lista_.inicio;      //iterator
    while(iterator != NULL){                        //percorrer a lista
        printf("%d|", iterator->tipo);
        iterator = iterator->newelemento;
    }

}

void inicializa_lista(struct lista *plista){
    plista->fim = NULL;
    plista->inicio = NULL;
}

void inserir_elemento(struct lista *plista, void *value){
    struct elemento *pelemento = (struct elemento*)malloc(sizeof(struct elemento));
    pelemento->tipo = value;
    pelemento->newelemento = NULL;

    if(plista->inicio == NULL){ //lista vazia
        plista->inicio = pelemento;
        plista->fim = pelemento;
    }else{
        plista->fim->newelemento = pelemento;
        plista->fim = pelemento;
    }
}

void remover_elemento(struct lista *plista, void *tormv){
    struct elemento *pant, *pprox;
    pant = plista->inicio;
    pprox = plista->inicio;

    while(pprox != NULL){

        if(pprox->tipo == tormv){
            if(plista->inicio == pprox){
                plista->inicio = plista->inicio->newelemento;
                free(pprox);
                break;
            }else{
                if(plista->fim = pprox){
                    plista->fim = pant;
                }
                pant->newelemento = pprox->newelemento;
                free(pprox);
                break;
            }
        }else{
            pant = pprox;
            pprox = pprox->newelemento;
        }
    }
}

