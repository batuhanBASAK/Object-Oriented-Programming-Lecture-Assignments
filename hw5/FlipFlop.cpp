#include "FlipFlop.h"


namespace hw5
{
    // The constructor that takes name of gate and input gate.
    FlipFlop::FlipFlop(string name, Gate *inputGate)
        : Gate(name, FLIPFLOP), inputGate(inputGate), former_out(false)
    {
        // Initially empty.
    }


    // Evaluates the Gate and returns the evaluated output.
    bool FlipFlop::evaluateGate()
    {
        if (isGateEvaluated)
        {
            // Gate has been evalueated and output has been setted already.
            // just return output.
            return getOutput();
        }

        bool output;

        bool input = inputGate->evaluateGate();


        output = (!input && former_out) || (input && !former_out);
        // Set new former_out
        former_out = output;

        // Set output.
        setOutput(output);

        // Set the flag.
        isGateEvaluated = true;

        return output;
    }
}