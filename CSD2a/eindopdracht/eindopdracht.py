import pygame
import time
import random


BPM = 120
note_16th_duration = 60 / BPM / 4
slice_length = 16


#initializing sound and player
pygame.mixer.init()
pygame.mixer.set_num_channels(3)

kick_channel = pygame.mixer.Channel(0)
snare_channel = pygame.mixer.Channel(1)
hihat_channel = pygame.mixer.Channel(2)

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
    'durations': []
}
snare = {
    'timestamps': [], 
    'instrumentname': "snare", 
    'instrument': snare_sound,
    'channel': snare_channel,
    'sequence': [],
    'durations': []
}
hihat = {
    'timestamps': [], 
    'instrumentname': "hihat", 
    'instrument': hihat_sound,
    'channel': hihat_channel,
    'sequence': [],
    'durations': []
}



#------ TEXT TO BINARY ------#
text = input('Input your text please \n')

def text_to_binary():
    binary_list = [bit for char in text for bit in format(ord(char), '08b')]
    return list(map(int, binary_list))

binary_list = text_to_binary()
sequence_length = len(binary_list)//3

def slicer(slice_length, list):
    sliced_sequence = []

    slice_start = random.randrange(len(list) - slice_length)

    for _ in range(slice_length):
        sliced_sequence.append(list.pop(slice_start))

    return sliced_sequence

#text to sequence
def generate_text_sequence(instrument):
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
    # print(f"Playing: {event['name']} at {event['ts']}")
    event['channel'].play(event['sample'])



#------ PLAYBACK ------#
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
        time.sleep(0.001)
    
    time.sleep(note_16th_duration)
    

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
