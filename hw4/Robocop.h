#ifndef ROBOCOP_H
#define ROBOCOP_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Humanic.h"


namespace PA4
{
    class Robocop : public Humanic
    {
    public:
        Robocop(int strenght, int hitPoint);
    };
}


#endif