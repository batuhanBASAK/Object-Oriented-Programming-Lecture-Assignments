// Or.h
// Interface file for class Or.

#ifndef OR_H
#define OR_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Gate.h"

namespace hw5
{
    class Or : public Gate
    {
    public:
        // The constructor that takes name of gate and two Gate pointer
        // for the inputs.
        Or(string name, Gate* firstGate, Gate* secondGate);

        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate();

    private:
        // Pointer of input Gates.
        Gate* firstGate;
        Gate* secondGate;
    };
} // End of namespace hw5




#endif