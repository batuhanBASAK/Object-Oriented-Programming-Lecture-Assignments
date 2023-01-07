
#include "Decoder.h"

namespace hw5
{
    Decoder::Decoder(Gate* out1,  // First output gate.
                     Gate* out2,  // Second output gate.
                     Gate* out3,  // Third output gate.
                     Gate* out4,  // Fourth output gate.
                     Gate* in1,   // First input gate.
                     Gate* in2)   // Second output gate.
    
        : Gate("decoder", DECODER), out1(out1), out2(out2), out3(out3), out4(out4),
          in1(in1), in2(in2)
    {
        // Intentionally empty.
    }


    // Evaluates the Gate and returns the evaluated output.
    bool Decoder::evaluateGate()
    {
        if (isGateEvaluated)
        {
            // Gate has been evalueated and output has been setted already.
            // just return output.
            return getOutput();
        }

        bool input1 = in1->evaluateGate();
        bool input2 = in2->evaluateGate();
        bool output;

        if (!input1 && !input2)
        {
            // Case: 00
            out1->setOutput(true);
            out2->setOutput(false);
            out3->setOutput(false);
            out4->setOutput(false);
        }
        else if (!input1 && input2)
        {
            // Case: 01
            out1->setOutput(false);
            out2->setOutput(true);
            out3->setOutput(false);
            out4->setOutput(false);
        }
        else if (input1 && !input2)
        {
            // Case: 10
            out1->setOutput(false);
            out2->setOutput(false);
            out3->setOutput(true);
            out4->setOutput(false);
        }
        else
        {
            // Case: 11
            out1->setOutput(false);
            out2->setOutput(false);
            out3->setOutput(false);
            out4->setOutput(true);
        }

        // Set the flag.
        isGateEvaluated = true;

        return output;
    }






}