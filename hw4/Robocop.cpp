#include "Robocop.h"

namespace PA4
{

    using std::cout;
    using std::cin;
    using std::string;
    using std::endl;

    Robocop::Robocop(int strenght, int hitPoint)
        : Humanic(1, strenght, hitPoint)
    {}
}