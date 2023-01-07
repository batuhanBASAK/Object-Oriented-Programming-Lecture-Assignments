#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Humanic.h"

namespace PA4
{

    class Optimusprime : public Humanic
    {
    public:
        Optimusprime(int strength, int hitPoint);
        
        int getDamage() const override;

    private:
        // Strong attack chance optimusprime can hit in percentage.
        static const int strongAttackChance = 15;
    };

}


#endif