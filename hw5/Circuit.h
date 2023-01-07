#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "Gate.h"
#include "Input.h"
#include "Output.h"
#include "Not.h"
#include "And.h"
#include "Or.h"
#include "FlipFlop.h"
#include "Decoder.h"

namespace hw5
{
    using namespace std;

    class Circuit
    {
    public:
        // Reads circuit file and bulids the circuit.
        Circuit(string filename);
        
        // Frees and clear vector.
        ~Circuit();

        // Returns index of gate.
        int searchIndexOfGate(string gateName);

        // Evaluates circuit. And prints the result to the output.
        void evaluateCircuit(vector<bool> inputs);

        // Resets all the gates.
        void resetGates();

        // Prints output gates.
        void printOutputs();

    private:
        // Array of cicuit components to store each gate.
        vector<Gate*> gates;

        // output values
        bool output1, output2, output3, output4;
    };
} // End of namespace hw5


#endif