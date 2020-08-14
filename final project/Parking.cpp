//
//  Parking.cpp
//  M1
//
//  Created by Shabnoor Sayed on 2020-07-17.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
/*------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Parking.h"
#include "Menu.h"
#include "ReadWritable.h"
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "iostream"
#include <cstring>
#include <stdio.h>
#include <fstream>

using namespace std;
namespace sdds {

    Parking::Parking()
    {
        park_name = nullptr;
        park_menu = nullptr;
        park_vehicle = nullptr;
        num_park_vehicle = 0;
        available_park_spots = 0;
        spots_num = 0;
        for(int i = 0; i < MAX_NUMBER_OF_PARKING_SPOTS; i++) {
            park_spots[i] = nullptr;
        }
        
    }

    Parking::Parking(const char* dataFile, int num_spots)
    {
        
        park_name = nullptr;
        park_menu = nullptr;
        park_vehicle = nullptr;
        num_park_vehicle = 0;
        available_park_spots = 0;
        spots_num = 0;
        for(int i = 0; i < MAX_NUMBER_OF_PARKING_SPOTS; i++) {
            park_spots[i] = nullptr;
        }
        if ((dataFile != nullptr && strlen(dataFile) > 0) && num_spots >=10 && num_spots < MAX_NUMBER_OF_PARKING_SPOTS) {
            park_name = new char[strlen(dataFile) + 1];
            strcpy(park_name, dataFile);
            spots_num = num_spots;
            for(int i = 0; i < MAX_NUMBER_OF_PARKING_SPOTS; i++) {
                park_spots[i] = nullptr;
            }
            if (!loadDataFile()) {
                cout << "Error in data file" << endl;
            } else {
                Menu tempMenu("Parking Menu, select an action:", 0);
                tempMenu << "Park Vehicle" << "Return Vehicle" << "List Parked Vehicles" << "Close Parking (End of day)" << "Exit Program";
                park_menu = tempMenu;
                Menu tempVehicle("Select type of the vehicle:", 1);
                tempVehicle << "Car" << "Motorcycle" << "Cancel";
                park_vehicle = tempVehicle;
            }
        } else {
            park_name = nullptr;
            park_menu = nullptr;
            park_vehicle = nullptr;
            num_park_vehicle = 0;
            available_park_spots = 0;
            spots_num = 0;
            for(int i = 0; i < MAX_NUMBER_OF_PARKING_SPOTS; i++) {
                park_spots[i] = nullptr;
            }
        }
    }

    Parking::~Parking()
    {
        saveDataFile();
        delete [] park_name;
        park_name = nullptr;
        for(int i = 0; i < MAX_NUMBER_OF_PARKING_SPOTS; i++) {
            park_spots[i] = nullptr;
        }
    }

    bool Parking::isEmpty()
    {
        bool result = true;
        
        if(park_name != nullptr) {
            result = false;
        }
        return result;
    }

     void Parking::parkingStatus()
    {
        cout << "****** Seneca Valet Parking ******" << endl;
        cout << "*****  Available spots: ";
        cout.width(4);
        cout << left << (spots_num - num_park_vehicle) << " *****" << endl;
        cout.unsetf(ios::left);
    }

    void Parking::parkingVehicle()
    {
        bool result = true;

        if(spots_num == num_park_vehicle) {
            cout << "Parking is full" << endl;
        } else {
            int option = park_vehicle.run();
            if(option == 1) {
                Vehicle* temp = new Car;
                temp->setCsv(false);
                temp->read(cin);
                for(int i = 0; i < spots_num; i++) {
                    if(result) {
                        if(park_spots[i] == nullptr) {
                            park_spots[i] = temp;
                            temp->setParkingSpot(i+1);
                            num_park_vehicle++;
                            cout << "\nParking Ticket" << endl;
                            cout << *temp << endl;
                            result = false;
                        }
                    } else {
                        temp = nullptr;
                    }
                }
            } else if(option == 2) {
                 Vehicle* temp = new Motorcycle;
                temp->setCsv(false);
                temp->read(cin);
                for(int i = 0; i < spots_num; i++) {
                    if(result) {
                        if(park_spots[i] == nullptr) {
                            park_spots[i] = temp;
                            temp->setParkingSpot(i+1);
                            num_park_vehicle++;
                            cout << "\nParking Ticket" << endl;
                            cout << *temp << endl;
                            result = false;
                        }
                    } else {
                        temp = nullptr;
                    }
                }
            } else {
                cout << "Parking cancelled" << endl;
            }
        }
    }

    void Parking::returnVehicle()
    {
        bool result = false;
        cout << "Return Vehicle" << endl;
        char tempLicense[10];
        cout << "Enter Licence Plate Number: ";
        cin.get(tempLicense, 10, '\n');
        while(strlen(tempLicense) > 8 || strlen(tempLicense) < 1) {
            cout << "Invalid Licence Plate, try again: ";
            cin.get(tempLicense, 10, '\n');
        }
        int length = strlen(tempLicense);
        for(int i = 0; i < length; i++) {
            tempLicense[i] = toupper(tempLicense[i]);
        }
        for(int i = 0; i < num_park_vehicle; i++) {
            if(park_spots[i] != nullptr && *park_spots[i] == tempLicense) {
                park_spots[i]->setCsv(false);
                cout << "\nReturning: " << endl;
                cout << *park_spots[i] << endl;
                delete park_spots[i];
                park_spots[i] = nullptr;
                num_park_vehicle--;
                result = true;
            }
        }
        if(result == false) {
            cout << "Licence plate " << tempLicense << " Not found" << endl;
            result = true;
        }
    }

    void Parking::listParkedVehicle()
    {
        cout << "*** List of parked vehicles ***" << endl;
        for(int i = 0; i < spots_num; i++) {
            if(park_spots[i] != nullptr) {
                this->park_spots[i]->setCsv(false);
                park_spots[i]->write(cout);
                cout << "-------------------------------" << endl;
            }
        }
    }

    bool Parking::closeParking()
    {
        if(isEmpty()){
            cout << "Closing Parking" << endl;
            return true;
        } else {
            cout << "This will Remove and tow all remaining vehicles from the parking!" << endl;
            cout << "Are you sure? (Y)es/(N)o: ";
            bool result = false;
            char option = cin.get();
            char enter = cin.get();
            cin.clear();
            while(result == false) {
                if(option == 'Y' || option == 'y') {
                    cout << "Closing Parking" << endl;
                    cout << endl;
                    for(int i = 0; i < spots_num; i++) {
                        if(park_spots[i] != nullptr) {
                            cout << "Towing request" << endl;
                            cout << "*********************" << endl;
                            this->park_spots[i]->setCsv(false);
                            this->park_spots[i]->write(cout);
                            delete park_spots[i];
                            park_spots[i] = nullptr;
                            num_park_vehicle--;
                        }
                        if(park_spots[i + 1] != nullptr) {
                            cout << endl;
                        }
                    }
                    result = true;
                    return true;
                } else if(option == 'N' || option == 'n') {
                    cout << "Aborted!" << endl;
                    result = true;
                    return false;
                } else if((option != 'Y' || option != 'y') && (option != 'N' || option != 'n') && (enter != '\n')) {
                    cin.clear();
                    cin.ignore(2000, '\n');
                    cout << "Invalid response, only (Y)es/(N)o are acceptable, retry: ";
                    cin >> option;
                }
            }
            cin.clear();
            return false;
        }
    }

    bool Parking::exitParkingApp()
    {
        cout << "This will terminate the program!" << endl;
        cout << "Are you sure? (Y)es/(N)o: ";
        bool result = false;
        char option[5];
        cin.width(5);
        cin >> option;
        cin.clear();
        cin.ignore(2000,'\n');
        option[0] = tolower(option[0]);
        
        if(option[0] == 'y' || option[0] == 'n') {
            result = true;
        }
        while(strlen(option) > 1 || !result) {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            cin.width(5);
            cin >> option;
            cin.clear();
            cin.ignore(2000,'\n');
            option[0] = tolower(option[0]);
            if(option[0] == 'y' || option[0] == 'n') {
                result = true;
            }
        }
            
        if(option[0] == 'y') {
            cout << "Exiting program!" << endl;
            saveDataFile();
            result = true;
        } else {
            result = false;
        }

        return result;
    }

    bool Parking::loadDataFile()
    {

        bool result = true;
        Vehicle* temp;
        int num = 0;

        if (!isEmpty()) {

            ifstream file(park_name, ios::in);

            if (!file.is_open() || isEmpty()) {
                result = true;
            }

            while (result && num < spots_num && file)
            {
                temp = nullptr;
                char type = '\0';

                file >> type;
                file.ignore();

                if (type == 'M') {
                    temp = new Motorcycle();
                    if (temp) {
                        temp->setCsv(true);
                        file >> *temp;
                        if (file) {
                            park_spots[temp->getParkingSpot() - 1] = temp;
                            num_park_vehicle++;
                        } else {
                            delete temp;
                            temp = nullptr;
                            result = false;
                        }
                    }
                } else if (type == 'C') {
                    temp = new Car();
                    if (temp) {
                        temp->setCsv(true);
                        file >> *temp;
                        if (file) {
                            park_spots[temp->getParkingSpot() - 1] = temp;
                            num_park_vehicle++;
                        } else {
                            delete temp;
                            temp = nullptr;
                            result = false;
                        }
                    }
                }
                num++;
            }
        }
        return result;
    }

    void Parking::saveDataFile()
    {
       
        if (!isEmpty())
        {
            ofstream fileOut(park_name);
            if (fileOut.is_open())
            {
                for (int i = 0; i < spots_num; i++)
                {
                    if (park_spots[i] != nullptr) {
                        park_spots[i]->setCsv(true);
                        fileOut << *park_spots[i];
                    }
                }
            }
        }
    }

    int Parking::run()
    {
        int num = 0;
        if (!isEmpty()) {
            int option;
            bool result = true;
            do {
                parkingStatus();
                option = park_menu.run();
                if(option == 1) {
                    parkingVehicle();
                } else if(option == 2) {
                    returnVehicle();
                } else if(option == 3) {
                    listParkedVehicle();
                } else if(option == 4) {
                    if(closeParking()){
                        result = false;
                    }
                } else {
                    if(exitParkingApp()) {
                        result = false;
                    }
                }
            } while (result);
            num = 0;
        } else {
            num = 1;
        }
        return num;
    }
}


