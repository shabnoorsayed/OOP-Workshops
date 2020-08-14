//
//  Menu.cpp
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
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;

namespace sdds {

    MenuItem::MenuItem()
    {
        itemTitle = nullptr;
    }
    
    MenuItem::MenuItem(const char* ti)
    {
        if(ti == nullptr) {
            itemTitle = nullptr;
        } else {
            itemTitle = new char[strlen(ti) + 1];
            strcpy(itemTitle, ti);
        }
    }

    ostream& MenuItem::display(ostream& os) const
    {
        if(this->itemTitle != nullptr && strlen(this->itemTitle) > 0)
            os << this->itemTitle << endl;
        return os;
    }

    MenuItem::~MenuItem()
    {
        delete [] itemTitle;
        itemTitle = nullptr;
    }

    Menu::Menu()
    {
        menuTitle = nullptr;
        menuItem = nullptr;
        indentation = 0;
        size = 0;
    }

    Menu::Menu(const char* ti, int indent)
    {
        menuTitle = nullptr;
        menuItem = nullptr;
        indentation = indent;
        size = 0;
        setTitle(ti);
    }

    Menu::Menu(const Menu& src)
    {
        menuTitle = nullptr;
        menuItem = nullptr;
        indentation = 0;
        size = 0;
        init(src.menuTitle, src.menuItem, src.indentation, src.size);
    }

    Menu& Menu::operator=(const Menu& src)
    {
        init(src.menuTitle, src.menuItem, src.indentation, src.size);
        return *this;
    }

    void Menu::setTitle(const char * ti)
    {
        if (menuTitle != nullptr)
        {
            delete[] menuTitle;
            menuTitle = nullptr;
        }
        if(ti != nullptr && ti[0] != '\0') {
            menuTitle = new char[strlen(ti)+1];
            strcpy(menuTitle, ti);
        }
    }

    void Menu::setItems(const MenuItem *item, int si)
    {
        if (item == nullptr || si < 0)
        {
            delete[] menuItem;
            menuItem = nullptr;
        } else {
            menuItem = nullptr;
            menuItem = new MenuItem[si];
            for (int i = 0; i < si; i++)
            {
                int length = int(strlen(item[i].itemTitle) + 1);
                menuItem[i].itemTitle = new char[length];
                strcpy(menuItem[i].itemTitle, item[i].itemTitle);
            }
        }
    }

    void Menu::init(const char* ti, const MenuItem* item, int indent, int si)
    {
        setTitle(ti);
        setItems(item, si);
        indentation = indent;
        size = si;
    }

    bool Menu::isEmpty() const
    {
        bool result = false;
        if(menuTitle == nullptr && menuItem == nullptr && size == 0) {
            result = true;
        } else {
            return false;
        }
        return result;
    }

    Menu::operator bool() const
    {
        bool result = false;
        if(!isEmpty()) {
            result = true;
        } else {
            result = false;
        }
        return result;
    }

    void Menu::display()const
    {
        if(isEmpty()) {
            cout << "Invalid Menu!" << endl;
        } else if(size <= 0 || menuItem == nullptr) {
            space(cout, 2);
            cout << menuTitle << endl;
            cout << "No Items to display!" << endl;
        } else {
            space(cout, indentation);
            cout << menuTitle << endl;
            for (int i = 0; i < size; i++)
            {
                space(cout, indentation);
                cout << (i + 1) << "- ";
                menuItem[i].display(cout);
            }
            space(cout, indentation);
            cout << "> ";
        }
    }

    int Menu::run() const
    {
        int option;
        bool result = false;
        display();
       
        if (size > 0) {
            while (result == false) {
                if (!(cin >> option)) {
                    cout << "Invalid Integer, try again: ";
                } else if (option <= 0 || option > size) {
                    cout << "Invalid selection, try again: ";
                } else {
                    result = true;
                }
                cin.clear();
                cin.ignore(2000, '\n');
            }
        }else {
            option = 0;
        }
        return option;
    }

    Menu::operator int() const
    {
        return run();
    }

    void Menu::add(const char* ti)
    {
        if(ti == nullptr) {
            delete [] menuTitle;
            menuTitle = nullptr;
            delete [] menuItem;
            menuItem = nullptr;
            indentation = 0;
            size = 0;
        } else if(ti != nullptr && ti[0] != '\0' && size < MAX_NO_OF_ITEMS && menuTitle != nullptr) {
            MenuItem* temp = new MenuItem[size+1];
            for(int i = 0; i < size; i++) {
                temp[i].itemTitle = new char[strlen(menuItem[i].itemTitle) + 1];
                strcpy(temp[i].itemTitle, menuItem[i].itemTitle);
            }
            temp[size].itemTitle = new char[strlen(ti) + 1];
            strcpy(temp[this->size].itemTitle, ti);
            
            if(menuItem != nullptr) {
                delete [] menuItem;
                menuItem = nullptr;
            }
            size++;
            menuItem = temp;
        }
    }

    Menu& Menu::operator<<(const char* ti)
    {
        add(ti);
        return *this;
    }

    Menu& Menu::operator=(const char* ti)
    {
        setTitle(ti);
        return *this;
    }

    Menu::~Menu()
    {
        delete [] menuTitle;
        menuTitle = nullptr;
        delete [] menuItem;
        menuItem = nullptr;
    }

    void space(ostream& os,int si)
    {
        int length = si * 4;
        for (int i = 0; i < length; i++)
        {
            os << " ";
        }
    }
}
