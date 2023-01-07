#ifndef HUMANIC_H
#define HUMANIC_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "Robot.h"


namespace PA4
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    class Humanic : public Robot
    {
    public:
        Humanic(int type, int strength, int hitPoint);

        virtual int getDamage() const override;

    private:
        // nuke attack chance in percetange.
        static const int nukeAttackChance = 10;
    };
    
}





#endif