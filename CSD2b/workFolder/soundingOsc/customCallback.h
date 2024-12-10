#include "audiocomponent.h"
//  Daan Schrier
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "osc.h"

struct CustomCallback : AudioCallback {
    explicit CustomCallback (double Fs) : AudioCallback(Fs) {

    }

    ~CustomCallback() override {

    }

    void prepare (int sampleRate) override {

    }

    void process (AudioBuffer buffer) override {
        auto [inputChannels, outputChannels, numInputChannels, numOutputChannels, numFrames] = buffer;

        for (int channel = 0u; channel < numOutputChannels; ++channel) {
            for (int sample = 0u; sample < numFrames; ++sample) {
                outputChannels[channel][sample] = 0.0f;
                // write sample to buffer at channel 0, amp = 0.25
                outputChannels[channel][sample] = sine.getSample();
                sine.tick();
            }
        }
    }

private:
//   Sine sine{220};
//   Saw saw{440};
    Sine sine{220};
    Sine sine2{440};
    Sine sine3{880};
    Sine sine4{1760};
};
