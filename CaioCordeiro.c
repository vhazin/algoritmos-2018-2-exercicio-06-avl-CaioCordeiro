#include <stdio.h>
#include <stdlib.h>
struct No{
    int info;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
    int altura;

};
int altura(struct No *no){
    if(no==NULL){
        return 0;
    }
    else{
        return no->altura;  
    }
}
int atualizarAltura(struct No *no){
    int altDireita;
    int altEsquerda;
    if(no!=NULL){
        altDireita = altura(no->direita);
        altEsquerda = altura(no->esquerda);
        if(altDireita>altEsquerda){
            no->altura=altDireita+1;
        }
        else{
            no->altura=altEsquerda+1;
        }
    }
    return 0;
}
struct No *criararvore(int info){
    struct No *raiz;
    raiz = (struct No *) malloc(sizeof(struct No));
    raiz->info = info;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    raiz->altura = 1;
    return raiz; 
}
struct No *inserir(int info,struct No *arvore){
    if(info!=-1){
    if(arvore==NULL){
        arvore=criararvore(info);
    }
    else if(info<arvore->info){
        arvore->esquerda = inserir(info,arvore->esquerda);
        arvore->esquerda->pai = arvore;
    }
    else{
        arvore->direita = inserir(info, arvore->direita);
        arvore->direita->pai = arvore;
    }
    atualizarAltura(arvore);
    return arvore;
    }
}
struct No * buscar_no(struct No * arvore,int valor){
    if(arvore==NULL){
        return NULL;
    }
    else{
        if (valor==arvore->info){
            return arvore;
        }
        if(valor<arvore->info){
            return (buscar_no(arvore->esquerda,valor));
        }
        else{
            return (buscar_no(arvore->direita,valor));
        }
    } 
}
int checkavl(struct No *arvore,int array[100],int n){
    int flag = 0;
    int x=1;
    int y=1;
    for(int i=0;i<(n);i++){
        if(array[i]!= -1){
            x = altura(buscar_no(arvore,array[i])->direita);
            y = altura(buscar_no(arvore,array[i])->esquerda);
            
            if((x-y)!=0){
                flag = flag+1;
                break;
            }
            else{
                continue;
            } 
            }
    else{
        continue;
    }
    }
    if(flag>0){
        printf("\nF");
    }
    else{
        printf("\nT");
    }
}
int main(){
    int t;
    int n;
    int node;
    int tint=0;
    int nint=0;
    int array[101];
    struct No *arvore=NULL;
    scanf("%d",&t);
    for(tint=0;tint<t;tint++){
        scanf("%d",&n);
        arvore = NULL;
        for(nint=0;nint<n;nint++){
            scanf("%d",&node);
            if(node== -1){
                array[nint]=node;
                continue;
            }
            else{
                arvore=inserir(node,arvore);
                array[nint]=node;
            }
        }
    checkavl(arvore,array,n);
    for(int j=0;j<100;j++){
        array[j]=0;
    }
    }
}
