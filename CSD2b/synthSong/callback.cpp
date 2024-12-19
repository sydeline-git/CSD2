#include "callback.h"

//calling audiocallback constructor and passing samplerate value
CustomCallback::CustomCallback (float sampleRate) 
    : AudioCallback (sampleRate), sampleRate(sampleRate) {

    std::cout << "Initializing CustomCallback" << "\n";

    //set default
    osc = &oscSine;
}

void CustomCallback::prepare (int newSampleRate) {
    //turn integer rate into float samplerate
    sampleRate = (float) newSampleRate;

    //setting samplerate in created osc
    oscSine.setSamplerate(sampleRate);
    oscSquare.setSamplerate(sampleRate);
    oscTriangle.setSamplerate(sampleRate);
    oscSaw.setSamplerate(sampleRate);

    std::cout << "Set samplerate to: " << sampleRate << "\n";

}

std::string CustomCallback::retrieveUserInput(std::string selectionOptions[], int numOptions) {
    // show user the allowed options
    std::cout << "Please enter your selection. You can choose from: ";
    for(int i = 0; i < numOptions - 1; i++) {
    std::cout << selectionOptions[i] << ", ";
    }
    // print last option outside forloop to end with an .
    std::cout << selectionOptions[numOptions - 1] << "." << std::endl;
    // retrieve and return choice
    std::string selection = "";
    std::cin >> selection;
    return selection;
}


int CustomCallback::retrieveUserSelection(std::string selectionOptions[], int numOptions) {
    std::string selection = "";
    while(true) {
    // let user choose from the allowed options
    selection = retrieveUserInput(selectionOptions, numOptions);

    // check if the selection is among the available option
    for(int i=0; i<numOptions; ++i) {
        if(selection == selectionOptions[i]) {
        return i;
        }
    }
    // if we end up here, this means the selection is not correct,
    // so log a message to user to try again
    std::cout << "Incorrect selection, please try again";
    } // while
    return -1; // should never be reached
} 

void CustomCallback::setWaveform(const std::string& waveform) {
    if (waveform == "square") {
        osc = &oscSquare;

    } else if (waveform == "triangle") {
        osc = &oscTriangle;

    } else if (waveform == "sine") {
        osc = &oscSine;

    } else if (waveform == "saw") {
        osc = &oscSaw;
    }
}

// void CustomCallback::setMelody(const std::string& melodyName) {
//     if (melodyName == "cmajor") {
//         melody = melody1;

//     } else if (melodyName == "dminor") {
//         melody = melody2;
//     }
// }

void CustomCallback::process (AudioBuffer buffer) {
    auto [inputChannels,
        outputChannels,
        numInputChannels,
        numOutputChannels,
        numFrames] = buffer;

    for (int channel = 0u; channel < numOutputChannels; ++channel) {
        for (int sample = 0u; sample < numFrames; ++sample) {
            outputChannels[channel][sample] = osc->getSample();
            osc->tick();

        if (frameIndex >= noteDelayFactor * sampleRate) {
            frameIndex = 0;
            updatePitch(melody, *osc);
        } else {
            frameIndex++;
        }

        }
    }
}

double CustomCallback::mtof (float mPitch){
    return 440.0 * pow (2.0, (mPitch - 69.0f) / 12.0f);
}

void CustomCallback::updatePitch (Melody& melody, Osc& Osc) {
    float note = melody.getNote();
    double freq = mtof (note);
    std::cout << "next note: " << note << ", has frequency " << freq
                << std::endl;
    osc->setFrequency (freq);
}
