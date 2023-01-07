#include "Bulldozer.h"

namespace PA4
{
    using std::cout;
    using std::cin;
    using std::string;
    using std::endl;

    Bulldozer::Bulldozer(int strength, int hitPoint)
        : Robot(3, strength, hitPoint)
    {}
}