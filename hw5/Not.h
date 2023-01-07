// Not.h
// Interface file for class Not.

#ifndef NOT_H
#define NOT_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Gate.h"

namespace hw5
{
    using namespace std;

    
    class Not : public Gate
    {
    public:
        // The constructor that takes name of gate and a Gate pointer
        // for the input.
        Not(string name, Gate* inputGate);

        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate();

    private:
        // Pointer of input Gate.
        Gate* inputGate;
    };
} // End of namespace hw5




#endif