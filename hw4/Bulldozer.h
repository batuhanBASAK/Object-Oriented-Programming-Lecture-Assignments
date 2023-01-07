#ifndef BULLDOZER_H
#define BULLDOZER_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Robot.h"

namespace PA4
{
    class Bulldozer : public Robot
    {
    public:
        Bulldozer(int strength, int hitPoint);
    };
}

#endif