//
//  Utils.cpp
//  MarkStats
//
//  Created by Shabnoor Sayed on 2020-05-31.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "Utils.h"
#include <string>
#include <cstdio>
using namespace std;

bool validateNumber(string value)
{
    if(!isdigit(value[0])) {
        cout << "Invalid Number, try again: ";
        return false;
    }
    return true;
}

bool validateTrailingNumber(string value)
{
    long size = value.length();
    for(int i=1; i<size; i++) {
        if(!isdigit(value[i])) {
            cout << "Invalid trailing characters, try again: ";
            return false;
        }
    }
    return true;
}

int strToInt(string value)
{
    int result = 0;
    long size = value.length();
    for(int i=0; i<size; i++) {
        result = result*10 + (value[i] - '0');
    }
    
    return result;
}

void bubbleSort(int value[], int size)
{
    int temp;
    
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(value[i] < value[j]) {
                temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for(int i=0; i< size; i++) {
        cout << arr[i];
        if(i<size-1){
            cout << ", ";
        }
    }
}
int sum(int arr[], int size)
{
    int sum = 0;
    for(int i=0; i< size; i++) {
        sum += arr[i];
    }
    return sum;
}

float average(int arr[], int size)
{
    float avg = sum(arr, size) / float(size);
    return avg;
}
