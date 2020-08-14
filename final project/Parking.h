//
//  Parking.hpp
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
#ifndef Parking_h
#define Parking_h
#include "Menu.h"
#include "Vehicle.h"
#include "iostream"
#include <cstring>
#include <stdio.h>

namespace sdds {

    const int MAX_NUMBER_OF_PARKING_SPOTS = 100;

    class Parking {
        
        int spots_num;
        Vehicle* park_spots[MAX_NUMBER_OF_PARKING_SPOTS];
        int num_park_vehicle;
        int available_park_spots;
        char* park_name;
        Menu park_menu;
        Menu park_vehicle;
        
        bool isEmpty(); 
        void parkingStatus();
        void parkingVehicle();
        void returnVehicle();
        void listParkedVehicle();
        bool closeParking();
        bool exitParkingApp();
        bool loadDataFile();
        void saveDataFile();
        
        
    public:
        Parking();
        Parking(const char*, int);
        ~Parking();
        Parking(Parking&) = delete;
        Parking& operator=(const Parking&) = delete;
        int run();
    };
}
#endif /* Parking_h */
