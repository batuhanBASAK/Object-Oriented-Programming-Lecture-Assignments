#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

#include "Robot.h"
#include "Humanic.h"
#include "Optimusprime.h"
#include "Robocop.h"
#include "Roomba.h"
#include "Bulldozer.h"



using std::cout;
using std::cin;
using std::endl;
using std::string;

using PA4::Robot;
using PA4::Humanic;
using PA4::Optimusprime;
using PA4::Robocop;
using PA4::Roomba;
using PA4::Bulldozer;


// Mathces two robots and returns the winner.
// Returns 0 if first robot wins, else returns 1.
int match(Robot* p1, Robot* p2)
{
    int robot1HitPoint;
    int robot2HitPoint;
    int robot1Damage;
    int robot2Damage;

    int counter = 1;


    cout << p1->getType() << " vs " << p2->getType() << endl << endl;

    while (true)
    {

        cout << "------------------- Round " << counter
             << " -------------------" << endl;

        // Make first robot hits to second one.
        cout << endl;
        robot1Damage = p1->getDamage();
        p2->decreaseHitPoint(robot1Damage);

        // If first robot wins return winner.
        if (p2->getHitPoint() <= 0)
            return 0;

        cout << endl;

        // Make second robot hits to first one.
        cout << endl;
        robot2Damage = p2->getDamage();
        p1->decreaseHitPoint(robot2Damage);

        // If second robot wins return winner.
        if (p1->getHitPoint() <= 0)
            return 1;

        // If no one wins yet then print the current hit points.
        cout << endl << endl;
        cout << p1->getType() << " hit point is "
             << p1->getHitPoint() << endl;
        
        cout << p2->getType() << " hit point is "
             << p2->getHitPoint() << endl;


        counter++;
    }
    
}

int main()
{
    srand(static_cast<int>(time(NULL)));
    Robot* p1;
    Robot* p2;

    cout << "------------------ Game 1 -------------------" << endl << endl;

    // Optimusprime vs Robocop
    p1 = new Optimusprime(50, 100);
    p2 = new Robocop(50, 100);

    if (match(p1, p2) == 0)
        cout << p1->getType() << " (First robot) wins" << endl;
    else
        cout << p2->getType() << " (Second robot) wins" << endl;
    cout << "--------------------------------------------" << endl;


    delete p1;
    delete p2;



    cout << endl << endl << endl;
    cout << "------------------ Game 2 ------------------" << endl << endl;

    // Bulldozer vs Roomba
    p1 = new Bulldozer(50, 100);
    p2 = new Roomba(50, 100);

    if (match(p1, p2) == 0)
        cout << p1->getType() << " (First robot) wins" << endl;
    else
        cout << p2->getType() << " (Second robot) wins" << endl;
    cout << "--------------------------------------------" << endl;
    
    delete p1;
    delete p2;


    cout << endl << endl << endl;
    cout << "------------------ Game 3 ------------------" << endl << endl;

    // Optimusprime vs Roomba
    p1 = new Optimusprime(50, 100);
    p2 = new Roomba(50, 100);

    if (match(p1, p2) == 0)
        cout << p1->getType() << " (First robot) wins" << endl;
    else
        cout << p2->getType() << " (Second robot) wins" << endl;
    cout << "--------------------------------------------" << endl;
    
    delete p1;
    delete p2;


    cout << endl << endl << endl;
    cout << "------------------ Game 4 ------------------" << endl << endl;

    // Roomba vs Robocop
    p1 = new Roomba(50, 100);
    p2 = new Robocop(50, 100);

    if (match(p1, p2) == 0)
        cout << p1->getType() << " (First robot) wins" << endl;
    else
        cout << p2->getType() << " (Second robot) wins" << endl;
    cout << "--------------------------------------------" << endl;
    
    delete p1;
    delete p2;


    return 0;
}