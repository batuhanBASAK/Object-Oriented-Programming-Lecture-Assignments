// Input.h
// Interface file for class Input.

#ifndef INPUT_H
#define INPUT_H


#include <iostream>
#include <cstdlib>
#include <string>

#include "Gate.h"


namespace hw5
{

    using namespace std;

    class Input : public Gate
    {
    public:
        Input(string name, bool inputValue);

        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate();

    private:
        bool inputValue; // value of input gate.
    };

}

#endif
