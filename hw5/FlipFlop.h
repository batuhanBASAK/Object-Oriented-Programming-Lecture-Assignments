// FlipFlop.h
// Interface file for class FlipFlop.

#ifndef FLIPFLOP_H
#define FLIPFLOP_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Gate.h"

namespace hw5
{
    using namespace std;

    class FlipFlop : public Gate
    {
    public:
        // The constructor that takes name of gate and input gate.
        FlipFlop(string name, Gate *inputGate);


        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate();

    private:
        Gate* inputGate;
        bool former_out;

    };
}


#endif