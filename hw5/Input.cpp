// Input.cpp
// Implementation file for class Input.


#include "Input.h"

namespace hw5
{
    using namespace std;
    
    Input::Input(string name, bool inputValue)
        : Gate(name, INPUT), inputValue(inputValue)
    {
        // Intentionally empty.
    }

    // Evaluates the Gate and returns the evaluated output.
    bool Input::evaluateGate()
    {
        if (isGateEvaluated)
        {
            // Gate has been evalueated and output has been setted already.
            // just return output.
            return getOutput();
        }
        
        // Set the flag.
        isGateEvaluated = true;

        // Return computed output.
        return getOutput();
    }
}
