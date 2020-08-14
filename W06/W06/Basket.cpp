//
//  Basket.cpp
//  W06
//
//  Created by Shabnoor Sayed on 2020-07-08.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"Basket.h"

namespace sdds
{
    Basket::Basket()
    {
        m_fruit = nullptr;
        m_cnt = 0;
        m_price = 0;
    }
    Basket::Basket(Fruit* fruit, int cnt, double price)
    {
        m_fruit = nullptr;
        m_cnt = 0;
        m_price = 0;
        if (fruit != nullptr && cnt > 0 && price > 0)
        {
            if(this->m_fruit){
                delete this->m_fruit;
            }
            if (fruit != nullptr)
            {
                m_fruit = new Fruit[cnt];
                for(int i = 0; i < cnt; i++) {
                    
                    m_fruit[i] = fruit[i];
                }

            }
            if (cnt > 0)
            {
                m_cnt = cnt;
            }
            else
            {
                m_cnt = 0;
            }
            setPrice(price);
        }
        else
        {
            m_fruit = nullptr;
            m_cnt = 0;
            m_price = 0;
        }
      }
    Basket::Basket(const Basket& src)
    {
         if (src.m_fruit)
        {
            m_cnt = src.m_cnt;
            m_price = src.m_price;
            m_fruit = new Fruit[m_cnt+1];
            for(int i = 0; i < m_cnt; i++) {
                
                m_fruit[i] = src.m_fruit[i];
            }
        }
        else
        {
            m_fruit = nullptr;
            m_cnt = 0;
            m_price = 0;
        }
    }
    Basket::~Basket()
    {
        if(m_fruit != nullptr) {
            delete[] m_fruit;
            m_fruit = nullptr;
        }
    }
    
    void Basket::setPrice(double price)
    {
        if (price > 0)
        {
            m_price = price;
        }
        else
        {
            m_price = 0;
        }
    }
    bool Basket::isempty() const
    {
        bool value = true;
        if (m_fruit == nullptr && m_cnt == 0 && m_price == 0)
        {
            value = true;
        }
        else
        {
            value = false;
        }
    return value;
    }
    
    Basket& Basket::operator+=(Fruit fruits)
    {
        if (m_fruit == nullptr)
        {
            m_fruit = new Fruit[1];
            m_fruit[0] = fruits;
            m_cnt = 1;
        }
        else
        {
            Fruit* temp_fruits = new Fruit[m_cnt + 1];
            for (int  i= 0; i < m_cnt; i++)
            {
                temp_fruits[i] = m_fruit[i];
            }
            delete[] m_fruit;
            m_fruit = nullptr;
            m_fruit = temp_fruits;
            m_fruit[m_cnt] = fruits;
            m_cnt++;
        }
        return *this;
    }
    
    Basket::operator bool()
    {
        bool value = true;
        if (!isempty())
        {
            value = true;
        }
        else
        {
            value = false;
        }
        return value;
    }

    std::ostream& operator<<(std::ostream& os, const Basket& bsk)
    {
        if (bsk.m_fruit)
        {
            os << "Basket Content:" << std::endl;
            for (int i = 0; i < bsk.m_cnt; i++)
            {
                os << std::fixed;
                os.precision(2);
                os.width(10);
                os << bsk.m_fruit[i].m_name << ": ";
                os << bsk.m_fruit[i].m_qty << "kg" << std::endl;
            }
            os << "Price: " << bsk.m_price << std::endl;
            os.unsetf(std::ios::fixed);
            os.precision(6);
        }
        else
        {
            os << "The basket is empty!" << std::endl;
        }
        return os;
    }
}
