#include "Robot.h"

namespace PA4
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;


    // Constructors
    Robot::Robot()
        : type(0), strength(50), hitPoint(100)
    {}
    Robot::Robot(int newType, int newStrength, int newHitPoint)
        : type(newType), strength(newStrength), hitPoint(newHitPoint)
    {}

    // Getter functions
    string Robot::getType() const
    {
        string tmp;
        switch(type)
        {
            case 0: tmp = "optimusprime"; break;
            case 1: tmp = "robocop"; break;
            case 2: tmp = "roomba"; break;
            case 3: tmp = "bulldozer"; break;
            default: tmp = "unknown";
        }
        return tmp;
    }

    int Robot::getStrength() const
    {
        return strength;
    }
    int Robot::getHitPoint() const
    {
        return hitPoint;
    }

    // Setter functions
    void Robot::setType(int newType)
    {
        type = newType;
    }
    void Robot::setStrength(int newStrength)
    {
        strength = newStrength;
    }
    void Robot::setHitPoint(int newHitPoint)
    {
        hitPoint = newHitPoint;
    }

    // Decrease hitPoint.
    void Robot::decreaseHitPoint(int decrement)
    {
        hitPoint = hitPoint - decrement;
    }


    int Robot::getDamage() const
    {
        int damage;

        damage = (rand() % strength) + 1;
        cout << getType() << " attacks for " << damage << " points!" << endl;
        return damage;
    }
    
}