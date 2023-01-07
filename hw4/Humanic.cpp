#include "Humanic.h"

namespace PA4
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;


    Humanic::Humanic(int type, int strength, int hitPoint)
        : Robot(type, strength, hitPoint)
    {}

    int Humanic::getDamage() const
    {
        int damage = Robot::getDamage();

        int tmp = (rand() % 100) + 1;
        bool hitNukeAttack = (tmp <= nukeAttackChance) ? true : false;

        if (hitNukeAttack)
        {
            damage = damage + 50;
            cout << getType()
                 <<  " inflicts for 50 point bonus Nuke Attack!!!" << endl;
        }
        return damage;
    }


}