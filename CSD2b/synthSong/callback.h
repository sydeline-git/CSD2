#pragma once

#include "audiocomponent.h" //be able to acces juce library

#include "sine.h"
#include "triangle.h"
#include "square.h"
#include "saw.h"
#include "melody.h"

//new class which inherits from audiocallback
class CustomCallback : public AudioCallback {

public:
    CustomCallback(float sampleRate);  //create constructor with variable samplerate

    void prepare(int sampleRate) override;     //override prepare function in audiocomponent
    void process(AudioBuffer buffer) override;

    int retrieveUserSelection(std::string selectionOptions[], int numOptions);
    std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

    // void setMelody(const std::string& melody);
    void setWaveform(const std::string& waveform);

    double mtof(float mPitch);
    void updatePitch(Melody& melody, Osc& osc);


private:
    float sampleRate = 48000;

    Melody melody;
    int frameIndex = 0;
    double noteDelayFactor = 0.2;

    Osc* osc = nullptr;

    // //creating oscilators objects
    Sine oscSine {220, sampleRate};
    Square oscSquare {220, sampleRate};
    Triangle oscTriangle {220, sampleRate};
    Saw oscSaw {220, sampleRate};
};

