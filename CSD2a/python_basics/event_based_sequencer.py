import pygame
import time

BPM = 120
note_16th_duration = 60 / BPM / 4

#initializing sound and player
pygame.mixer.init()

kick = pygame.mixer.Sound("sounds/kick.wav")
snare = pygame.mixer.Sound("sounds/snare.wav")
hihat = pygame.mixer.Sound("sounds/hihat.wav")

kick = {
    'timestamps': [], 
    'instrumentname': "kick", 
    'instrument': kick,
    'sequence': [1,0,0,0, 1,0,0,0,  1,0,0,0,  1,0,0,0],
    'durations': []
}
snare = {
    'timestamps': [], 
    'instrumentname': "snare", 
    'instrument': snare,
    'sequence': [0,0,0,0,  1,0,0,0,  0,0,0,0,  1,0,0,0],
    'durations': []
}
hihat = {
    'timestamps': [], 
    'instrumentname': "hihat", 
    'instrument': hihat,
    'sequence': [1,0,1,0,  1,0,1,0,  1,0,1,0,  1,0,1,0],
    'durations': []
}


def create_timestamp(ts, sample):
    return {'ts': ts, 'sample': sample}

events = []

def binary_to_timestamps(instrument):
    if instrument['sequence'][i] == 1:
        events.append(create_timestamp(i*note_16th_duration, instrument['instrumentname']))

for i in range(16):
    binary_to_timestamps(kick)
    binary_to_timestamps(snare)
    binary_to_timestamps(hihat)

def handle_note_event(event):
    print(event['instrumentname'])
    event['instrument'].play()

#functie voor spelen juiste smaple of juist moment



print(events)



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
