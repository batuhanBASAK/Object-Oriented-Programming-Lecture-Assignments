#include "Circuit.h"

namespace hw5
{
    using namespace std;

    // Reads circuit file and bulids the circuit.
    Circuit::Circuit(string filename)
    {
        ifstream circuitFile;
        circuitFile.open(filename);
        if (circuitFile.fail())
        {
            // Error happened while opening file!
            // Print an error message and quit the program.
            cout << "Error: Opening file " << filename << endl;
            cout << "Program Stopping..." << endl;
            exit(EXIT_FAILURE);
        }

        string gateName; // Name of gate.
        string gateType; // Type of gate.

        string line;
        string tmp1, tmp2;


        bool endRead = false;
        while (!endRead)
        {
            if (circuitFile >> gateType)
            {
                if (gateType == "INPUT")
                {
                    getline(circuitFile, line); // read left line.
                    stringstream s(line); // create a line stream.
                    while(s >> gateName)
                    {
                        gates.push_back(new Input(gateName, false));
                    }
                }
                else if (gateType == "OUTPUT")
                {
                    // Gate type is output

                    // Get first output
                    circuitFile >> gateName;
                    gates.push_back(new Output(gateName));


                    // Get second output
                    circuitFile >> gateName;
                    gates.push_back(new Output(gateName));


                    // Get third output
                    circuitFile >> gateName;
                    gates.push_back(new Output(gateName));

                    // Get fourth output
                    circuitFile >> gateName;
                    gates.push_back(new Output(gateName));
                }
                else if (gateType == "AND")
                {
                    // Gate type is and

                    circuitFile >> gateName;

                    circuitFile >> tmp1 >> tmp2;
                    gates.push_back(new And(gateName, 
                        gates[searchIndexOfGate(tmp1)], 
                        gates[searchIndexOfGate(tmp2)]));
                }
                else if (gateType == "OR")
                {
                    // Gate type is or
                    circuitFile >> gateName;

                    circuitFile >> tmp1 >> tmp2;
                    gates.push_back(new Or(gateName, 
                        gates[searchIndexOfGate(tmp1)], 
                        gates[searchIndexOfGate(tmp2)]));
                }
                else if (gateType == "NOT")
                {
                    // Gate type is not
                    circuitFile >> gateName;
                    circuitFile >> tmp1;
                    gates.push_back(new Not(gateName, 
                        gates[searchIndexOfGate(tmp1)]));
                }
                else if (gateType == "FLIPFLOP")
                {
                    // Gate type is flipflop
                    circuitFile >> gateName;
                    circuitFile >> tmp1;
                    gates.push_back(new FlipFlop(gateName,
                        gates[searchIndexOfGate(tmp1)]));
                }
                else
                {
                    // Gate type is decoder
                    string o1, o2, o3, o4, i1, i2;
                    circuitFile >> o1 >> o2 >> o3 >> o4 >> i1 >> i2;
                    gates.push_back(new Decoder(gates[searchIndexOfGate(o1)],
                        gates[searchIndexOfGate(o2)],
                        gates[searchIndexOfGate(o3)],
                        gates[searchIndexOfGate(o4)],
                        gates[searchIndexOfGate(i1)],
                        gates[searchIndexOfGate(i2)]));
                }
            }
            else
            {
                endRead = true;
            }
        }

        circuitFile.close();
    }


    // Frees and clear vector.
    Circuit::~Circuit()
    {
        int i;
        for (i = 0; i < gates.size(); i++)
            delete gates[i];

        gates.clear();
    }


    // Returns index of gate.
    int Circuit::searchIndexOfGate(string gateName)
    {
        int i;
        int ans = -1;
        for (i=0; i < gates.size(); i++)
        {
            if (gateName == gates[i]->getName())
            {
                ans = i;
                break;
            }
        }

        return ans;
    }


    // Evaluates circuit. And prints the result to the output.
    void Circuit::evaluateCircuit(vector<bool> inputs)
    {
        // Set inputs.
        int i;
        for (i = 0; i < inputs.size(); i++)
            gates[i]->setOutput(inputs[i]);

        // Evaluate decoder to evaluate all circuit.
        gates[gates.size()-1]->evaluateGate();
    }

    // Resets all the gates.
    void Circuit::resetGates()
    {
        int i;
        for (i = 0; i < gates.size(); i++)
            gates[i]->resetGateEvaluation();
    }

    // Prints output gates.
    void Circuit::printOutputs()
    {
        int indexOfBegining;
        
        // Find beggining index of outputs.
        int i;
        for (i=0; i < gates.size(); i++)
        {
            if (gates[i]->getType() == OUTPUT)
            {
                indexOfBegining = i;
                break;
            }
        }

        // print output gates.
        cout << gates[indexOfBegining]->evaluateGate() << " "
             << gates[indexOfBegining+1]->evaluateGate() << " "
             << gates[indexOfBegining+2]->evaluateGate() << " "
             << gates[indexOfBegining+3]->evaluateGate() << " " << endl;

    }

} // End of namespace hw5