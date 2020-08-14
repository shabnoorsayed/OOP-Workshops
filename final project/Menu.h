//
//  Menu.hpp
//  M1
//
//  Created by Shabnoor Sayed on 2020-07-11.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//
/*------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef Menu_h
#define Menu_h
#include "iostream"
#include <stdio.h>
#include <cstring>
 
namespace sdds {
    const int MAX_NO_OF_ITEMS = 10;
    class Menu;

    class MenuItem
    {
        friend Menu;
    private:
        char* itemTitle;
        
        MenuItem();
        MenuItem(const char* ti);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        std::ostream& display(std::ostream&) const;
        ~MenuItem();
    };

    class Menu
    {
        char* menuTitle;
        MenuItem* menuItem;
        int indentation;
        int size;
    public:
        Menu();
        Menu(const char*, int indent = 0);
        Menu(const Menu&);
        Menu& operator=(const Menu&);
        void setTitle(const char*);
        void setItems(const MenuItem*,int);
        void init(const char*, const MenuItem*, int, int);
        operator bool() const;
        operator int() const;
        bool isEmpty() const;
        void display() const;
        void add(const char*);
        int run() const;
        Menu& operator=(const char*);
        Menu& operator<<(const char*);
        ~Menu();
    };

    void space(std::ostream&,int);
}

#endif /* Menu_h */
