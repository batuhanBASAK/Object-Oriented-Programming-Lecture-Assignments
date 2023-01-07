#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"


namespace PA4
{
    class Roomba : public Robot
    {
    public:
        Roomba(int strength, int hitPoint);

        int getDamage() const override;
    };
}



#endif
