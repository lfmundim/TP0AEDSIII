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
    *root = trieMakeNode('\0', FALSE);
}

trieT *trieMakeNode(char key, int end){ //aloca node
    trieT *node = NULL;
    node = (trieT*)malloc(sizeof(trieT));
    if(!node){
        printf("Alocacao de memoria falhou. Encerrando.\n");
        return NULL;
    }
    node->key = key;
	for(int i=0; i<26; i++){
		node->children[i] = NULL;
	}
	node->end = end;
	node->count = FALSE;
    return node;
}

void insertNode(trieT **root, char key, int end){
	trieT* node;
	int keyCode = key-65;

	node = trieMakeNode(key, end);
	if(!&(*root)->children[keyCode])
		(*root)->children[keyCode] = node;
	if(end==TRUE)
		node->end = TRUE;
}
//TODO
int trieSearch(trieT *root, char *key, char op){//procura letra a letra
	int i, keyCode[26];
	for(i=0; i<strlen(key); i++){
		keyCode[i] = key[i]-65;
	}
	for(i=0; i<strlen(key); i++){
		if(!root->children[keyCode[i]]->key)
			return 0;
		else{

		}
	}
}
