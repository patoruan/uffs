#include<stdio.h>
#include<stdlib.h> 

/*
Ruan Natan Guerra Pato
Trabalho de Implementação - Árvore AVL (Adelson Velsky e Landis)

Implementar em C a partir do código em anexo, as seguintes funções em uma Árvore de Busca Binária Balanceada (AVL):

* Implemente/Descubra o que falta na função de Inserção e Remoção;

* Função de Rotação Esquerda;

* Função de Rotação Direita;

* Função de impressão de percurso em pré ordem;

* Função de impressão de percurso em em ordem;

* Função de impressão de percurso em pós ordem;

Ex.: Sequência em Pré Ordem: 4(FB=0)2(FB=0)1(FB=0)3(FB=0)5(FB=-1)6(FB=0)
*/

typedef struct nodo{
    int info; // Informação armazenada na árvore
    struct nodo *esquerda,*direita; // Nodos em sequência
    int fb; // Fator de balanceamento
}nodo;

void allFB(nodo *node);
nodo *inserir(nodo *node,int); // Insere um nodo na árvore
nodo *Delete(nodo *node,int); // Deleta um nodo da árvore
void preordem(nodo *node); // Exibe os nodos em prordem
void emordemFB(nodo *node); //
void emordem(nodo *node); // Exibe os nodos emordem
void posordem(nodo *node); // Exibe os nodos em posordem
int altura(nodo *node); // Retorna a altura da árvore
nodo *rotacaodireita(nodo *node); // Rotação Right
nodo *rotacaoesquerda(nodo *node); // Rotação Left
nodo *RR(nodo *node); // Faz rotação Right-Right
nodo *LL(nodo *node); // Faz rotaçao Left-Left
nodo *LR(nodo *node); // Faz rotação Left-Right
nodo *RL(nodo *node); // Faz rotação Righut-Left
int FB(nodo *node);
 
int main(){
    nodo *root = NULL;
    int x,n,i,op;
    
    do{
        printf("\n1)Criar");
        printf("\n2)Inserir");
        printf("\n3)Deletar");
        printf("\n4)Imprimir");
        printf("\n5)Sair");
        printf("\n\nInforme a sua escolha: ");
        scanf("%d",&op);
        
        switch(op){
            case 1:
                printf("\nInforme o número de elemetos: ");
                scanf("%d",&n);
                printf("\nEntre com o elementos da árvore: ");
                root=NULL;
                for(i=0;i<n;i++){
                    scanf("%d",&x);
                    root = inserir(root, x);
                }
                allFB(root);
                break;
                
            case 2:
                printf("\nInforme um dado: ");
                scanf("%d",&x);
                root = inserir(root,x);
                allFB(root);
                break;
                    
            case 3:
                printf("\nInforme um dado:");
                scanf("%d",&x);
                root = Delete(root,x);
                allFB(root);
                break;
            
            case 4: 
                printf("\nSequência em Pré Ordem: ");
                preordem(root);
                printf("\n\nSequência Em Ordem: ");
                emordem(root);
                printf("\n\nSequência Pós Ordem: ");
                posordem(root);
                printf("\n");
                break;
        }
    }while(op!=5);
    
    return 0;
}
 
void allFB(nodo *node){   //allFB - Fator de Balanceamento
    if(node!=NULL){
        node->fb = altura(node);
        allFB(node->esquerda);
        node->fb = altura(node);
        /*if(node->direita != NULL && node->esquerda != NULL)
            printf("(FB=%d)Node = %d, (FB=%d)Node->direita = %d, (FB=%d)Node->esquerda = %d\n", node->fb, node->info, node->direita->fb, node->direita->info, node->esquerda->fb, node->esquerda->info);
        else if(node->esquerda != NULL)
            printf("(FB=%d)Node = %d, (FB=%d)Node->esquerda = %d\n", node->fb, node->info, node->esquerda->fb, node->esquerda->info);
        else if(node->direita != NULL)
            printf("(FB=%d)Node = %d, (FB=%d)Node->direita = %d\n", node->fb, node->info, node->direita->fb, node->direita->info);
        else
            printf("(FB=%d)Node = %d\n", node->fb, node->info);*/
        allFB(node->direita);
    }
}

nodo *inserir(nodo *T,int x){
    if(T==NULL){
        nodo *novo = (nodo*) malloc(sizeof(nodo));
        novo->info = x;
        novo->esquerda = NULL;
        novo->direita = NULL;
        novo->fb = FB(novo);
        return novo;
    }else
        if(x > T->info){ // insira na subárvore direita
            T->direita = inserir(T->direita, x);
            if(FB(T) == -2)
                if(x > T->direita->info)
                    T = RR(T);
                else
                    T = RL(T);
        }else
            if(x < T->info){
                T->esquerda = inserir(T->esquerda, x);
                if(FB(T) == 2)
                    if(x < T->esquerda->info)
                        T = LL(T);
                    else
                        T = LR(T);
            }
        
        T->fb = altura(T);
        
        return(T);
}
 
nodo * Delete(nodo *T,int x){
    nodo *p;

    if(T==NULL){
        return T;
/*    if(x > T->info)
        T->direita = Delete(T-direita, x);
    else if(x < T->info)
        T->esquerda = Delete(T->esquerda, x);
    else{
        if(T->direita == NULL && T->esquerda == NULL){
            free(T);
            T = NULL;
        }else if(T->esquerda != NULL && T->direita == NULL){
            nodo *aux = T->esquerda;
            T = T->esquerda;
            free(aux);
        }else if(T->direita != NULL && T->esquerda == NULL){
            nodo *aux = T->direita;
            T = T->direita;
            free(aux);
        }else{
            nodo *aux = menorNodo(T->direita);
            T->info = aux->info;
            T->direita = Delete(T->direita, aux->info);
        }
    }

    if(T==NULL)//{
        return T;*/
    }else
        if(x > T->info){ // Insira na subárvore esquerda
            T->direita = Delete(T->direita,x);
            if(FB(T) == 2)
                if(FB(T->esquerda) >= 0)
                    T = LL(T);
                else
                    T = LR(T);
        }else
            if(x < T->info){
                T->esquerda = Delete(T->esquerda, x);
                if(FB(T) == -2)    // Rebalancear durante a conclusão
                    if(FB(T->direita) <= 0)
                        T = RR(T);
                    else
                        T = RL(T);
            }else{
                // Os dados a serem excluídos são encontrados
                if(T->direita != NULL){    // Delete seu sucessor Em Ordem
                    p = T->direita;
                //printf("\nSequência em Pré Ordem: ");
                //preordem(T);
                    
                    while(p->esquerda != NULL)
                        p = p->esquerda;
                    
                    T->info = p->info;
                    T->direita = Delete(T->direita, p->info);
                    
                    if(FB(T)==2)// Rebalancear durante a conclusão
                        if(FB(T->esquerda)>=0)
                            T = LL(T);
                        else
                            T = LR(T);\
                }
                else
                    return(T->esquerda);
            }
    T->fb = altura(T);
    return(T);
}

int altura(nodo *node){
    int sae,sad;
    if(node==NULL)
        return(0);
    
    if(node->esquerda==NULL)
        sae=0;
    else
        sae=1+node->esquerda->fb;
        
    if(node->direita==NULL)
        sad=0;
    else
        sad=1+node->direita->fb;
    
    if(sae>sad)
        return(sae);
    
    return(sad);
}
 
nodo * rotacaodireita(nodo *node){
    nodo *aux0 = node->esquerda, *aux1 = node->direita;
    
    aux0->direita = node;
    node->esquerda = aux1;
    
    node->fb = FB(node);
    aux0->fb = FB(aux0);

    return aux0;
}
 
nodo * rotacaoesquerda(nodo *node){
    nodo *aux2 = node->direita, *aux3 = node->esquerda;

    aux2->esquerda = node;
    node->direita = aux3;

    node->fb = FB(node);
    aux2->fb = FB(aux2);

    return aux2;
}
 
nodo * RR(nodo *node){
    node = rotacaoesquerda(node);
    return(node);
}
 
nodo * LL(nodo *node){
    node = rotacaodireita(node);
    return(node);
}
 
nodo * LR(nodo *node){
    node->esquerda = rotacaoesquerda(node->esquerda);
    node = rotacaodireita(node);
    
    return(node);
}
 
nodo * RL(nodo *node){
    node->direita = rotacaodireita(node->direita);
    node = rotacaoesquerda(node);
    return(node);
}
 
int FB(nodo *node){   //FB - Fator de Balanceamento
    int sae,sad; //sae - sub-árvore-esquerda | sad - sub-árvore-direita
    if(node==NULL)
        return(0);
 
    if(node->esquerda==NULL)
        sae=0;
    else
        sae=1+node->esquerda->fb;
 
    if(node->direita==NULL)
        sad=0;
    else
        sad=1+node->direita->fb;
 
    return(sae-sad);
}
 
// Imprime o percurso preordem 
void preordem(nodo *node){
    if(node!=NULL){
        printf("%d(FB=%d)", node->info, node->fb);
        preordem(node->esquerda);
        preordem(node->direita);
    }
}
 
// Imprime o percurso emordem 
void emordem(nodo *node){
    if(node!=NULL){
        emordem(node->esquerda);
        printf("%d(FB=%d)", node->info, node->fb);
        emordem(node->direita);
    }
}
 
void emordemFB(nodo *node){
    if(node!=NULL){
        emordem(node->esquerda);
        node->fb = FB(node);
        //printf("%d(FB=%d)", node->info, node->fb);
        emordem(node->direita);
    }
} 

// Imprime o percurso posordem 
void posordem(nodo *node){
    if(node!=NULL){
        posordem(node->esquerda);
        posordem(node->direita);
        printf("%d(FB=%d)", node->info, node->fb);
    }
} 
