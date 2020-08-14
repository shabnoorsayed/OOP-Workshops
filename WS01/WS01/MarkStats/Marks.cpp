//
//  Marks.cpp
//  MarkStats
//
//  Created by Shabnoor Sayed on 2020-05-31.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include "Marks.h"
#include "Utils.h"
#include <string>
using namespace std;

void markstat()
{
    cout << "Mark Stats Program."<< endl << endl;
    char assessment[41];
    string n;
    cout << "Please enter the assessment name: ";
    cin.getline(assessment, 41);
    cout << "Please enter the number of marks: ";
    cin >> n;
    
    while(!validateNumber(n) || !validateTrailingNumber(n) || !validateMarksInRange(n)) {
        cin >> n;
    }
    
    int marks = strToInt(n);
    
    cout << "Please enter " + to_string(marks) + " marks (0<=Mark<=100):" << endl;
    
    int valueOfMarks[marks];
    
    for(int i=0; i<marks; i++) {
        string input;
        cout << to_string(i+1) + "> ";
        cin >> input;
        
        while(!validateNumber(input) || !validateTrailingNumber(input) || !validateMarksValueInRange(input)) {
            cin >> input;
        }
        valueOfMarks[i] = strToInt(input);
    }
    cout << "Thank you..." << endl;
    cout << "Assessment Name: " << assessment << endl;
    cout << "----------------" << endl;
    //Sorting
    bubbleSort(valueOfMarks, marks);
    printArray(valueOfMarks, marks);
    cout << endl;
    // Avg
    float avg = average(valueOfMarks, marks);
    cout.precision(1);
    cout << "Average: " << fixed << avg << endl;
    //passing
    cout << "Number of Passing Marks: ";
    cout << countPassing(valueOfMarks, marks);
    return;
}

bool validateMarksInRange(string n)
{
    int marks = strToInt(n);

    if(marks > 50 || marks < 5) {
        cout << "Invalid value (5<=value<=50), try again: ";
        return false;
    }
    
    return true;
}

bool validateMarksValueInRange(string n)
{
    int value = strToInt(n);

    if(value > 100 || value < 0) {
        cout << "Invalid value (0<=value<=100), try again: ";
        return false;
    }
    
    return true;
}

int countPassing(int arr[], int size)
{
    int count = 0;
    for(int i=0; i< size; i++) {
        if(arr[i]>=50){
            count++;
        }
    }
    return count;
}
