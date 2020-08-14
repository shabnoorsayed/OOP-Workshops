//
//  Engine.cpp
//  W05
//
//  Created by Shabnoor Sayed on 2020-06-28.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds
{

    Engine::Engine()
    {
        m_size = 0;
        m_type[0] = '\0';
    }
    Engine::Engine(const char arr[], double size)
    {
        if (size > 0 && arr[0] != '\0')
        {
            m_size = size;
            strcpy(m_type, arr);
        }
        else
        {
            m_size = 0;
            m_type[0] = '\0';
        }

    }
    double Engine::get() const
    {
        return m_size;
    }
    void Engine::display() const
    {
        cout <<m_size<<" liters - "<<m_type<<endl;
    }
}
