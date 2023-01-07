#include "Optimusprime.h"

namespace PA4
{

    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    Optimusprime::Optimusprime(int strength, int hitPoint)
        : Humanic(0, strength, hitPoint)
    {}
        
    int Optimusprime::getDamage() const
    {
        int damage = Humanic::getDamage();

        int tmp = (rand() % 100) + 1;
        bool hitStrongAttack = (tmp <= strongAttackChance) ? true : false;

        if (hitStrongAttack)
        {
            damage = 2 * damage;
            cout << getType() << " inflicts for double attack!!!" << endl;
            cout << getType() << " total damage is " << damage << endl;

        }

        return damage;
    }
}