// Output.cpp
// Implementation file for class Output.

#include "Output.h"

namespace hw5
{
    using namespace std;

    // The constructor that takes name and output value of gate.
    Output::Output(string name)
        : Gate(name, OUTPUT)
    {
        // Intentionally empty.
    }


    // Evaluates the Gate and returns the evaluated output.
    bool Output::evaluateGate()
    {
        return getOutput();
    }
}