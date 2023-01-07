// Gate.h
// Interface file for class Gate.


#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


namespace hw5
{

    using namespace std;

    // Types of Gate as an abstract data type.
    enum GateType {INPUT=0, OUTPUT, AND, OR, NOT, FLIPFLOP, DECODER};

    class Gate
    {
    public:
        // The constructor that takes name and type of Gate.
        Gate(string name, GateType type);

        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate() = 0;

        // Returns the type of gate.
        GateType getType() const;

        // Returns the name of gate.
        string getName() const;


        // Assigns parameter output to output of gate.
        void setOutput(bool output);
    

        // Returns the output of gate.
        // It is a helper function for function evaluateGate.
        bool getOutput() const;


        // Resets the variable isGateEvaluated to use function
        // evaluateGate for next iterations.
        void resetGateEvaluation();

    private:
        string name;     // Name of gate.
        GateType type;   // Type of gate.
        bool output;     // output of gate.

    protected:

        // variable that holds information about
        // gate has been evaluated or not.
        // It helps to avoid evaluating gate more than once. Instead
        // after first evaluation it makes function evaluateGate to return
        // output which is already evaluated.
        bool isGateEvaluated;
    };


} // End of namespace hw5


#endif