#include <iostream>

class Note {
public:
    //define constructor
    Note();
 
    void play();        //void == no return function

    int getVelocity();  //function that returns integer

    int midiNoteValue;
    int velocity;
};

Note::Note() {
    std::cout << "Note - Constructor \n";
    midiNoteValue = 0;
    velocity = 0; 
}

void Note::play() {
    std::cout << "Playing note: " << midiNoteValue << " at velocity" << velocity << std::endl;
}

int Note::getVelocity() {
    return velocity;
}

int main() {
    Note aNote;

    aNote.midiNoteValue = 60;
    aNote.velocity = 127;
    aNote.play();
}


