//
// Created by heimdallr on 22/08/16.
//

#include "trie.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

void makeTrie(trieT **root){
    *root = trieMakeNode('\0', -1, FALSE);
}

trieT *trieMakeNode(char key, int position, int last){ //aloca node
    trieT *node = NULL;
    node = (trieT*)malloc(sizeof(trieT));
    if(!node){
        printf("Alocacao de memoria falhou. Encerrando.\n");
        return NULL;
    }
    node->key = key;
    node->height = position;
    node->next = NULL;
    node->prev = NULL;
    node->children = NULL;
    node->parent = NULL;
    node->count = 0;
    if(last==FALSE) node->end = FALSE;
    else node->end = TRUE;
    return node;
}

void insertNode(trieT **root, char key, int position, int last){
    trieT *node;
    if((*root)->height != position){ //filho
        if(!(*root)->children){ //primeiro filho
            node = trieMakeNode(key, position, last);
            node->parent = *root;
        }
        else{ //segundo filho em diante
            insertNode(&(*root)->children, key, position, last);
        }
    }
    if((*root)->height == position){ //irmão
        if((*root)->key == key){ //se o node for a mesma letra
            if(last==TRUE){ //se for final de palavra
                (*root)->end = TRUE;
            }
            else return; //se nao for final de palavra
        }
        else if(!(*root)->next){//não tem next
            node = trieMakeNode(key, position, last);
            (*root)->next = node;
        }
        else{ //tem next
            insertNode(&(*root)->next, key, position, last);
        }
    }
}

int trieSearch(trieT *root, char key, char op){//procura letra a letra
    if(root->key == key){ //match de letra
        if(root->end == TRUE){
            if(op =='F') root->count++;
            else if(op == 'P')
                printf("%d ", root->count);
        }
        return 1;
    }
    else if(root->next){ //se mais nodes no nivel
        trieSearch(root->next, key, op);
    }
    else //sem match no nivel
        return 0;
}

void trieMatch(trieT *root, char *key, char op){ //procura a palavra; chama a trieSearch
    int i;
    char *string;
    string = (char*)calloc(strlen(key),sizeof(char));
    for(i=0; i<strlen(key); i++){
        if(trieSearch(root, key[i], op)==1)
            string[i]=1;
        else
            break;
    }
}