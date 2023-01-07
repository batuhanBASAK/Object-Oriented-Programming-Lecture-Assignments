#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>


namespace PA4
{

    using std::string;

    class Robot
    {
    public:
        
        // Constructors
        Robot();
        Robot(int newType, int newStrength, int newHitPoint);

        // Getter functions
        string getType() const;
        int getStrength() const;
        int getHitPoint() const;

        // Setter functions
        void setType(int newType);
        void setStrength(int newStrength);
        void setHitPoint(int newHitPoint);

        // Decrease hitPoint.
        void decreaseHitPoint(int decrement);


        virtual int getDamage() const;

    private:
        int type;
        int strength;
        int hitPoint;
    };

}


#endif