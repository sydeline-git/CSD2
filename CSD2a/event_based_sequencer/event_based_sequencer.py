import pygame
import time

BPM = 120
note_16th_duration = 60 / BPM / 4

#initializing sound and player
pygame.mixer.init()

kick_sound = pygame.mixer.Sound("sounds/kick.wav")
snare_sound = pygame.mixer.Sound("sounds/snare.wav")
hihat_sound = pygame.mixer.Sound("sounds/hihat.wav")


#events
kick = {
    'timestamps': [], 
    'instrumentname': "kick", 
    'instrument': kick_sound,
    'sequence': [1,0,0,0, 1,0,0,0,  1,0,0,0,  1,0,0,0],
    'durations': []
}
snare = {
    'timestamps': [], 
    'instrumentname': "snare", 
    'instrument': snare_sound,
    'sequence': [0,0,0,0,  1,0,0,0,  0,0,0,0,  1,0,0,0],
    'durations': []
}
hihat = {
    'timestamps': [], 
    'instrumentname': "hihat", 
    'instrument': hihat_sound,
    'sequence': [1,0,1,0,  1,0,1,0,  1,0,1,0,  1,0,1,1],
    'durations': []
}


#dictionary in list function
def create_timestamp(ts, sample, name):
    return {'ts': ts, 'sample': sample, 'name': name}


#transforming binary sequence in to usable timestamps
events = []
def binary_to_timestamps(instrument, i):
    if instrument['sequence'][i] == 1:
        events.append(create_timestamp(i*note_16th_duration, instrument['instrument'], instrument['instrumentname']))


#utilising function
for i in range(16):
    binary_to_timestamps(kick, i)
    binary_to_timestamps(snare, i)
    binary_to_timestamps(hihat, i)


#handling event 
def handle_note_event(event):
    print(event['name'])
    event['sample'].play()

events_temp = events

#playback
while True:
    events = events_temp[:]
    time_start = time.time()

    while events:
        event = events[0]
        time_now = time.time() - time_start

        if time_now >= event['ts']:
            if events:
                handle_note_event(events.pop(0))
            else:
                break
        time.sleep(0.01)
    
    time.sleep(note_16th_duration)
    



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
