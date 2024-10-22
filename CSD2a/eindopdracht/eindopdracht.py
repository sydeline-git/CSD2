import pygame
import time
import random
import math
import sys
import threading
from midiutil import MIDIFile


#initializing sound and player
pygame.mixer.init()
pygame.mixer.set_num_channels(3)


#setting up seperate channels so the audio can overlap
kick_channel = pygame.mixer.Channel(0)
snare_channel = pygame.mixer.Channel(1)
hihat_channel = pygame.mixer.Channel(2)

#defining sound file locations
kick_sound = pygame.mixer.Sound("sounds/kick.wav")
snare_sound = pygame.mixer.Sound("sounds/snare.wav")
hihat_sound = pygame.mixer.Sound("sounds/hihat.wav")


#events
kick = {
    'timestamps': [], 
    'instrumentname': "kick", 
    'instrument': kick_sound,
    'channel': kick_channel,
    'sequence': [],
    'durations': [],
    'midi': 35
}
snare = {
    'timestamps': [], 
    'instrumentname': "snare", 
    'instrument': snare_sound,
    'channel': snare_channel,
    'sequence': [],
    'durations': [],
    'midi': 38
}
hihat = {
    'timestamps': [], 
    'instrumentname': "hihat", 
    'instrument': hihat_sound,
    'channel': hihat_channel,
    'sequence': [],
    'durations': [],
    'midi': 42
}


#------ GETTING USER INPUTS ------#
def time_signature_to_16th_notes(numerator, denominator):    
    slice_length = numerator * (16 / denominator) 
    return slice_length


def get_time_signature():
    time_signature = input('Please enter the time signature of your sequence in the following format "_/_". \n')
    
    try:
        numerator, denominator = map(int, time_signature.split('/')) 
        return numerator, denominator
    
    except ValueError:
        print('Input invalid! Please enter the time signature in the before mentioned format.')
        return get_time_signature()


def get_measures():
    try:
        measures = int(input('How many measures should the sequence consist of? \n'))

    except ValueError:
        print('Please enter a valid integer')
        return get_measures()

    return measures


def get_text(slice_length):
    text_minimum = math.ceil((slice_length / 8)*3) + 1      
    print('Input your text:')

    while True:
        text = input()
        
        if len(text) < text_minimum:
            print('Input your text with a minimum of', text_minimum, 'charachters please.')
        else:
            return text
        

def get_BPM():
    while True:
        try:
            BPM_input = input("What BPM would you like to play at? Press enter for standard of 120.\n")

            if BPM_input == "": 
                BPM = 120
                print("Standard BPM of", BPM, "chosen.")
            else:
                BPM = int(BPM_input)
                print("BPM of", BPM, "chosen.")    
            break

        except ValueError:
            print("Enter a valid integer please.")
            continue
    return BPM
    

#performing the inputs        
numerator, denominator = get_time_signature() 
slice_length = int(get_measures() * time_signature_to_16th_notes(numerator, denominator))
BPM = get_BPM()
note_16th_duration = 60 / BPM / 4



def run_program():
    #------ TEXT TO BINARY ------#
    text = get_text(slice_length)

    #convert the inputted text into its binary components (HELP FROM CHATGPT)
    def text_to_binary():
        binary_list = [bit for char in text for bit in format(ord(char), '08b')]  #convert every character of text into binary of string '_' len(8)
        return list(map(int, binary_list))                                        #turn strings into actual integers

    binary_list = text_to_binary()
    sequence_length = len(binary_list)//3 

    #slice a portion of the full binary list according to the inputted values
    def slicer(slice_length, list):         
        sliced_sequence = []

        slice_start = random.randrange(len(list) - slice_length)    #slice list start position at random point

        for _ in range(slice_length):
            sliced_sequence.append(list.pop(slice_start))

        return sliced_sequence

    #binary list to sequence
    def generate_text_sequence(instrument):
        instrument['sequence'] = []

        temp_sequence = []
        
        for _ in range(sequence_length):
            if binary_list:
                temp_sequence.append(binary_list.pop(0))

        sliced_sequence = slicer(slice_length, temp_sequence)

        instrument['sequence'].extend(sliced_sequence)
        print(instrument['instrumentname'], instrument['sequence'])



    #------ CREATE SEQUENCES ------#
    generate_text_sequence(kick)
    generate_text_sequence(snare)
    generate_text_sequence(hihat)



    #------ SEQUENCE TO TIMESTAMPS ------#
    #dictionary in list function
    def create_timestamp(ts, sample, name, channel):
        return {'ts': ts, 'sample': sample, 'name': name, 'channel': channel}

    #transforming binary sequence in to usable timestamps
    events = []
    def binary_to_timestamps(instrument, i):
        if instrument['sequence'][i] == 1:
            events.append(create_timestamp(i*note_16th_duration, instrument['instrument'], instrument['instrumentname'], instrument['channel']))

    #utilising function
    for i in range(slice_length):
        binary_to_timestamps(kick, i)
        binary_to_timestamps(snare, i)
        binary_to_timestamps(hihat, i)

    #handling event 
    def handle_note_event(event):
        event['channel'].play(event['sample'])


    #------ MIDI SETUP ------#
    track       = 0
    channel     = 9  # aka channel 10 drums
    moment      = 0
    tempo       = BPM
    duration    = note_16th_duration
    velocity    = 100

    beat = MIDIFile(1)
    beat.addTrackName(track, moment, "Generated Beat")
    beat.addTempo(track, moment, tempo)


    #creating midi file
    def create_midi_file():
        #writing data onto midi file
        def add_onto_midifile(instrument):
            moment = 0

            for hits in instrument['sequence']:
                if hits == 1:
                    beat.addNote(track, channel, instrument['midi'], moment, duration, velocity)
                moment = moment + 0.25  #0.25 for sixteenth note

        #writing data onto
        add_onto_midifile(kick)
        add_onto_midifile(snare)
        add_onto_midifile(hihat)

        #actually create the file
        print("Midi File Created")
        with open("beat.mid", "wb") as output_file:
            beat.writeFile(output_file)



    #------ PLAYBACK ------#
    events_temp = events    
    print("Press CTRL+C to interupt loop")

    #playback
    while True:
        try:
            events = events_temp[:] #copy of original list from start to finish
            time_start = time.time()

            while events:
                event = events[0]
                time_now = time.time() - time_start

                if time_now >= event['ts']:
                    if events:
                        handle_note_event(events.pop(0))
                    else:
                        break
                time.sleep(0.001)
            
            time.sleep(note_16th_duration)
        
        except KeyboardInterrupt:
            user_input = input("Do you want to save the MIDI file (y/n)? ") 
            if user_input == 'y':
                create_midi_file()
                sys.exit()
                break      
            elif user_input == 'n':
                run_program()

run_program()

# swing_ratio = 0.6

# def swing(events, swing_ratio):
#     swing_amount = (swing_ratio - 0.5) * note_16th_duration * 2

#     for event in events:
#         beat_index = int(event['ts'] / note_16th_duration) % slice_length  # Get the 16th note index (0 to 7)
#         print(beat_index)
#         if beat_index % 2 == 1:  # Apply swing only to offbeats (index 1, 3, 5, 7)
#             event['ts'] += swing_amount  # Delay the offbeat by the swing amount
#     return events
            
# events = swing(events, swing_ratio)


# generate_binary_sequence(kick, sequence_length)
# generate_binary_sequence(snare, sequence_length)
# generate_binary_sequence(hihat, sequence_length)


# #------ RANDOM BINARY ------#
# #generate random 1 or 0
# def random_binary():
#     return int(random.random() >= 0.5)

# #create random sequence
# def generate_binary_sequence(instrument, length):
#     temp_sequence = [random_binary() for _ in range(length)]
#     instrument['sequence'].extend(temp_sequence)
#     print(instrument['instrumentname'], instrument['sequence'])





# event = events.pop(0)
# handle_note_event(event)
# time.sleep(1)





#functie voor spelen juiste smaple of juist moment



# list = []

# list.append(create_timestamp(1, kick['instrumentname']))

# print(list)
# # timestamp  = i * note_16th_duration














#lists of dictionarys

# kick = {
#     'timestamps': [], 
#     'instrumentname': "kick", 
#     'instrument': kick,
#     'durations': []
# }
# snare = {
#     'timestamps': [], 
#     'instrumentname': "snare", 
#     'instrument': snare,
#     'durations': []
# }
# hihat = {
#     'timestamps': [], 
#     'instrumentname': "hihat", 
#     'instrument': hihat,
#     'durations': []
# }

# def create_events(ts_seq, sample_id):
#     events = []
#     for ts in ts_seq:
#         events.append({'ts': ts, 'sample_id': sample_id})
#     return events

# def get_sequence(seq):
#     return seq['sequence']

# print(get_sequence(hihat))

# for i in len(hihat['sequence']):
#     if hihat['sequence'](i) == 1:
#         print()




        

# def handle_note_event(event):
#     print(event['instrumentname'])
#     event['instrument'].play()





# # timestamp = {'sample: 'kick', 'ts': 0.75}

# # def event_handler():
