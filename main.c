#include <stdlib.h>
#include <stdio.h>
#include "solving.h"

int main(int argc, char *argv[]){
    char *dictionary, *text;
    unsigned long int dic_words, text_words;
    trieT *trie = (trieT*)calloc(1,sizeof(trieT));

    scanf("%ld", &dic_words);
    getchar();
    fflush(stdin);
    dictionary = (char*)calloc((unsigned long int)16*dic_words, sizeof(char));
    fgets(dictionary, 16*dic_words, stdin);
    scanf("%ld", &text_words);
    getchar();
    fflush(stdin);
    text = (char*)calloc((unsigned long int)16*text_words, sizeof(char));
    fgets(text, 16*text_words, stdin);
    puts(text);


    makeDictionary(trie, dictionary);
    wordCounting(trie, text, text_words);
    printCounts(trie, dictionary);

    return 0;
}