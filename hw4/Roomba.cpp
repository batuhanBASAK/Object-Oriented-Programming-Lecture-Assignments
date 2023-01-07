#include "Roomba.h"

namespace PA4
{

    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;

    Roomba::Roomba(int strength, int hitPoint)
        : Robot(2, strength, hitPoint)
    {}

    int Roomba::getDamage() const
    {
        int damage = Robot::getDamage();

        // make double attack.
        damage = 2 * damage;
        cout << getType() << " inflicts for double attack!!!" << endl;
        cout << getType() << " total damage is " << damage << endl;

        return damage;
    }
}