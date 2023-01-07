// Gate.cpp
// Implementation file for class Gate.

#include "Gate.h"

namespace hw5
{
    using namespace std;

    // The constructor that takes name and type of Gate.
    Gate::Gate(string name, GateType type)
        : name(name), type(type), isGateEvaluated(false)
    {
        // Intentionally empty.
    }

    // Returns the type of gate.
    GateType Gate::getType() const
    {
        return type;
    }

    // Returns the name of gate.
    string Gate::getName() const
    {
        return name;
    }

    // Assigns parameter output to output of gate.
    void Gate::setOutput(bool output)
    {
        this->output = output;
    }
    
    // Returns the output of gate.
    // It is a helper function for function evaluateGate.
    bool Gate::getOutput() const
    {
        return output;
    }
    

    // Resets the variable isGateEvaluated to use function
    // evaluateGate for next iterations.
    void Gate::resetGateEvaluation()
    {
        isGateEvaluated = false;
    }


}
