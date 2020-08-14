//
//  Utils.hpp
//  W01P1
//
//  Created by Shabnoor Sayed on 2020-06-09.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#ifndef Utils_h
#define Utils_h
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

namespace sdds
{
    char ToLower(char ch);
    int StrCmp(const char* s1, const char* s2);
    void StrCpy(char* des, const char* src);
    int StrLen(const char* str);
    bool isAlpha(char ch);
void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif /* Utils_h */
