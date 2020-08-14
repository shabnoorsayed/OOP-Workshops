//
//  Basket.hpp
//  W06
//
//  Created by Shabnoor Sayed on 2020-07-08.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#pragma once
#ifndef SDDS_BASKET_H__
#define SDDS_BASKET_H__
 namespace sdds
{
    struct Fruit
    {
      char m_name[30 + 1]; // the name of the fruit
      double m_qty;        // quantity in kilograms
    };
     class Basket
    {
             Fruit* m_fruit;
             int m_cnt;
             double m_price;
        public:
            Basket();
           Basket(Fruit* fruit, int cnt, double price);
           Basket(const Basket& src);
            ~Basket();
           void setPrice(double price);
            bool isempty() const;
            operator bool();
           Basket& operator+=(Fruit fruits);
           
        friend std::ostream& operator<<(std::ostream& os, const Basket& bsk);

    };
}
#endif /* Basket_h */
