// And.cpp
// Implementation file for class And.

#include "And.h"

namespace hw5
{

    using namespace std;

    // The constructor that takes name of gate and two Gate pointer
    // for the inputs.
    And::And(string name, Gate* firstGate, Gate* secondGate)
        : Gate(name, AND), firstGate(firstGate), secondGate(secondGate)
    {
        // Intentionally empty.
    }


    // Evaluates the Gate and returns the evaluated output.
    bool And::evaluateGate()
    {
        bool input1, input2;


        if (isGateEvaluated)
        {
            // Gate has been evalueated and output has been setted already.
            // just return output.
            return getOutput();
        }

        // Evaluate input gates.
        input1 = firstGate->evaluateGate();
        input2 = secondGate->evaluateGate();

        // Compute the output
        bool output = input1 && input2;
        setOutput(output); // Set the output.
        
        // Set the flag.
        isGateEvaluated = true;

        // Return computed output.
        return output;
    }

}
