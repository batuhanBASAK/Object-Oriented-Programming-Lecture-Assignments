#include "Not.h"

namespace hw5
{
    using namespace std;

    
    // The constructor that takes name of gate and a Gate pointer
    // for the input.
    Not::Not(string name, Gate* inputGate)
        : Gate(name, NOT), inputGate(inputGate)
    {
        // Intentionally empty.
    }

    // Evaluates the Gate and returns the evaluated output.
    bool Not::evaluateGate()
    {
        bool input;


        if (isGateEvaluated)
        {
            // Gate has been evalueated and output has been setted already.
            // just return output.
            return getOutput();
        }


        // Evaluates input gate.
        input = inputGate->evaluateGate();

        // Operate and operation between these two inputs and
        // return the result as output.

        // Compute the output
        bool output = !input;
        setOutput(output); // Set the output.
        
        // Set the flag.
        isGateEvaluated = true;

        // Return computed output.
        return output;
    }

} // namespace hw5
