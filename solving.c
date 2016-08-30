//
// Created by heimdallr on 29/08/16.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "trie.h"

void makeDictionary(trieT *trie, char *dictionary){
    char *aux;
    int i, last;

    makeTrie(&trie);

    aux = strtok(dictionary, " ");
    while(aux){
        for(i=0; i<strlen(aux); i++){
            last=0;
            if(i==strlen(aux))
                last=1;
            insertNode(&trie, aux[i], i+1, last);
        }
        aux = strtok(NULL, " ");
    }
}

void wordCounting(trieT *trie, char *text, int text_size){
    char *aux;
    int i;

    aux = strtok(text, " ");
    while(aux){
        for(i=0; i<text_size; i++) {
            trieMatch(trie, aux, 'F');
        }
        aux = strtok(NULL, " ");
    }

}

void printCounts(trieT *trie, char* dictionary){
    char *aux;

    aux = strtok(dictionary, " ");
    while(aux){
        trieMatch(trie, aux, 'P');
        aux = strtok(NULL, " ");
    }
    printf("\n");
}