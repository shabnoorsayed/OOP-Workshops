//
//  Word.hpp
//  W01P1
//
//  Created by Shabnoor Sayed on 2020-06-09.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#ifndef Word_h
#define Word_h
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

namespace sdds
{
    const int MAX_WORD_LEN = 21;
    const int MAX_NO_OF_WORDS = 500;
    const int SORT_BY_OCCURANCE = 1;
    const int SORT_ALPHABETICALLY = 0;

    struct Word
    {
        char letters[MAX_WORD_LEN];
        int count;
    };
    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    void title(const char* value, int len);
    void endList();
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void print(const Word* w, bool gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void wordStats();
    void programTitle();
}
#endif /* Word_h */
