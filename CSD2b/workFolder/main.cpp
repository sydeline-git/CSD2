#include <iostream>



class Note {
public:
    //  default constructor
    Note(); // same name as class name

    //  methods (a method is a function & a member of a class)
    // VOID == no return
    void play();

    // INT == returns integer
    int getVelocity();


    //  fields (a field is a member of a class)
    int midiNoteValue;
    int velocity;
};

Note::Note() {
    std::cout << "Note - constructor\n";
    midiNoteValue = 60;
    velocity = 127;
}

void Note::play() {
    std::cout << "PLAYING NOTE: " << midiNoteValue
        << " at velocity: " << velocity << std::endl;
}

int Note::getVelocity() {
    return velocity;
}

int main() {
    Note aNote;

    std::cout << "aNote.midiNoteValue contains: "
        << aNote.midiNoteValue << "\n";

    std::cout << "aNote.velocity contains: "
        << aNote.velocity << "\n";

    aNote.play();
}