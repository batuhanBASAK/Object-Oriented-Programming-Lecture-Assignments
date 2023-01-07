// Decoder.h
// Interface file for class Decoder.

#ifndef DECODER_H
#define DECODER_H

#include <iostream>
#include <cstdlib>
#include <string>

#include "Gate.h"


namespace hw5
{
    using namespace std;
    
    class Decoder : public Gate
    {
    public:
        Decoder(Gate* out1, Gate* out2, Gate* out3, Gate* out4,
            Gate* in1, Gate* in2);


        // Evaluates the Gate and returns the evaluated output.
        virtual bool evaluateGate();
        
    private:
        Gate* out1; // First output gate.
        Gate* out2; // Second output gate.
        Gate* out3; // Third output gate.
        Gate* out4; // Fourth output gate.

        Gate* in1; // First input gate.
        Gate* in2; // Second input gate.
    };


} // end of namespace hw5


#endif
