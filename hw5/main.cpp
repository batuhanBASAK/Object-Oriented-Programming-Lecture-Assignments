#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Gate.h"
#include "Input.h"
#include "Output.h"
#include "Not.h"
#include "And.h"
#include "Or.h"
#include "FlipFlop.h"
#include "Decoder.h"
#include "Circuit.h"


using namespace std;
using namespace hw5;

int main(int argc, char const *argv[])
{
    Circuit circuit("circuit.txt");
    ifstream infile;

    infile.open("input.txt");
    if (infile.fail())
    {
        // Error Happened while opening file!
        // Print an error message and quit the program.
        cout << "Error: Opening File input.txt" << endl;
        cout << "Program Stopping..." << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    vector<bool> inputs;
    bool tmp;
    int i;
    while (getline(infile, line))
    {
        // Read input.txt line by line.


        stringstream linestream(line);
        while (linestream >> tmp)
        {
            // get inputs from line
            inputs.push_back(tmp);
        }

        // Evaluate circuit respect to inputs.
        circuit.evaluateCircuit(inputs);

        // Print outputs.
        circuit.printOutputs();

        // Reset gates.
        circuit.resetGates();

        // clear inputs vector.
        inputs.clear();
    }

    // Close input.txt file.
    infile.close();
    return 0;
}
