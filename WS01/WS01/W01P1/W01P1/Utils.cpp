//
//  Utils.cpp
//  W01P1
//
//  Created by Shabnoor Sayed on 2020-06-09.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace sdds
{
   char ToLower(char ch) {
      if (ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
      return ch;
   }
   int StrCmp(const char* s1, const char* s2) {
      int i;
      for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++);
      return s1[i] - s2[i];
   }
   void StrCpy(char* des, const char* src) {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = 0;
   }
   int StrLen(const char* str) {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }
   bool isAlpha(char ch) {
      return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
   }
   void trim(char word[]) {
      int i;
      while (word[0] && !isAlpha(word[0])){
         StrCpy(word, word + 1);
      }
      i = StrLen(word);
      while (i && !isAlpha(word[i - 1])) {
         word[i-- - 1] = 0;
      }
   }
   void toLowerCaseAndCopy(char des[], const char source[]) {
      int i = 0, j = 0;
      for (; source[i] != 0; i++) {
         des[j++] = ToLower(source[i]);
      }
      des[j] = 0;
   }
}
