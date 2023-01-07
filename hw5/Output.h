// Output.h
// Interface file for class Output.


#ifndef OUTPUT_H
#define OUTPUT_H


#include <iostream>
#include <cstdlib>
#include <string>

#include "Gate.h"


namespace hw5
{
    using namespace std;

    class Output : public Gate
    {
    public:
        // The constructor that takes name and output value of gate.
        Output(string name);

        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate();

    private:
    };
}

#endif