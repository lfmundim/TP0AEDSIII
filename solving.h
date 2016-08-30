//
// Created by heimdallr on 29/08/16.
//

#ifndef TP0_SOLVING_H
#define TP0_SOLVING_H

#include "trie.h"

void makeDictionary(trieT *trie, char *dictionary);

void wordCounting(trieT *trie, char *text, int text_size);

void printCounts(trieT *trie, char* dictionary);

#endif //TP0_SOLVING_H
