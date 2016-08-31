//
// Created by heimdallr on 22/08/16.
//

#ifndef TP0_TRIE_H
#define TP0_TRIE_H

//typedef int valueT;

typedef struct trieT{
    char key;
    struct trieT* children[26];
    int end, count; //1 true 0 false
}trieT;

void makeTrie(trieT **root);
int trieSearch(trieT *root, char key, char op); //letra por letra
trieT *trieMakeNode(char key, int end);
void insertNode(trieT **root, char key, int end); //letra por letra (key)
void removeNode(trieT **root, char *key);
void killTrie(trieT *root);
void trieMatch(trieT *root, char *key, char op); //retorna true ou false no match da palavra

#endif //TP0_TRIE_H
