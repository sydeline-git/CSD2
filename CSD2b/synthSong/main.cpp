#include "callback.h"
#include <iostream>
// #include <thread>

int main() {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource (44100);

    
    //selecting waveform
    std::string waveFormOptions[4] = {"sine", "saw", "square", "triangle"};
    int numWaveFormOptions = 4;

    int waveTypeSelection = audioSource.retrieveUserSelection(waveFormOptions,numWaveFormOptions);

    // use the selected option to show the corresponding text
    std::cout << "You selected: " << waveFormOptions[waveTypeSelection] << std::endl;
    audioSource.setWaveform(waveFormOptions[waveTypeSelection]);


    // //selecting melody
    // std::string melodyOptions[2] = {"cmajor", "dminor"};
    // int numMelodyOptions = 2;

    // int melodySelection = audioSource.retrieveUserSelection(melodyOptions, numMelodyOptions);

    // std::cout << "You selected: " << melodyOptions[melodySelection] << std::endl;
    // audioSource.setMelody(melodyOptions[melodySelection]);

   
    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);

    std::cout << "Press q + Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}