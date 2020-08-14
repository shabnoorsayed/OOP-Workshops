#include <fstream>
#include <iostream>
#include <ctype.h>
#include "Parking.h"
using namespace std;
using namespace sdds;
void runParking() {
   Parking P("ParkingData.csv", 11);
   P.run();
}
void pause() {
   cout << "<------------------------" << endl << "Press Enter to continue...";
   cin.ignore(1000, '\n');
}
void ShowDatafile() {
   char ch;
   ifstream file("ParkingData.csv");
   cout << endl << "Content of ParkingData.csv after the program exits" << endl;
   cout << "-----------------------------------------------------------" << endl;
   while (file.get(ch)) {
      cout <<char(tolower(ch));
   }
   cout <<  "-----------------------------------------------------------" << endl;
}
int main() {
   cout << "Pass 1: ------->" << endl;
   runParking();
   ShowDatafile();
   pause();
   cout << "Pass 2: ------->" << endl;
   runParking();
   ShowDatafile();
   pause();
   cout << "Pass 3: ------->" << endl;
   runParking();
   ShowDatafile();
   return 0;
}
