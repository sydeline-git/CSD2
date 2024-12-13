#include "audiocomponent.h"
//  Daan Schrier
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "triangle.h"
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
                outputChannels[channel][sample] = triangle.getSample();
                triangle.tick();
            }
        }
    }

    void setFrequency(float newFreq) {
        triangle.setFrequency(newFreq);
    }

    void setWaveform(std::string waveform) {
        
    }

private:
    if (waveform == "Triangle") {
        Triangle triangle{220};
    }
        
};
