//
//  Engine.hpp
//  W05
//
//  Created by Shabnoor Sayed on 2020-06-28.
//  Copyright © 2020 Shabnoor Sayed. All rights reserved.
//

#pragma once
#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__
namespace sdds
{
const int TYPE_MAX_SIZE = 30;
    class Engine
    {
        double m_size;
        char m_type[TYPE_MAX_SIZE];

    public:

        Engine();
        Engine(const char[],double);
        double get() const;
        void display() const;
    };
 
}

#endif /* Engine_h */
