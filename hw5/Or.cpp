// Or.cpp
// Implementation file for class Or.

#include "Or.h"

namespace hw5
{

    using namespace std;

    // The constructor that takes name of gate and two Gate pointer
    // for the inputs.
    Or::Or(string name, Gate* firstGate, Gate* secondGate)
        : Gate(name, OR), firstGate(firstGate), secondGate(secondGate)
    {
        // Intentionally empty.
    }


    // Evaluates the Gate and returns the evaluated output.
    bool Or::evaluateGate()
    {
        bool input1, input2;


        if (isGateEvaluated)
        {
            // Gate has been evalueated and output has been setted already.
            // just return output.
            return getOutput();
        }


        // Evaluate two input gates.
        input1 = firstGate->evaluateGate();
        input2 = secondGate->evaluateGate();


        // Compute the output
        bool output = input1 || input2;
        
        setOutput(output); // Set the output.
        
        // Set the flag.
        isGateEvaluated = true;

        // Return computed output.
        return output;
    }

}