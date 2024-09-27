import time
import pygame

#initializing sound and player
pygame.mixer.init()
kick = pygame.mixer.Sound("sounds/kick.wav")
snare = pygame.mixer.Sound("sounds/snare.wav")
hihat = pygame.mixer.Sound("sounds/hihat.wav")

#lists
timestamps = []
timestamps_16th = []
note_durations = []

#ask user for BPM, if enter then standard of 120, if not integer repeat till is
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
    
beat_16th_duration = 60 / get_BPM() / 4

while True:
    try:
        num_playback_times = int(input("How many notes should the sequence consist of?\n"))
    except ValueError: 
        print("Please enter a valid integer")
        continue
    break

print("Please enter the duration of the notes")
def get_playback_time():
    for i in range(num_playback_times):
        note_durations.append(float(input()))

get_playback_time()

print(note_durations)

def durations_to_timestamps():
    total_dur = 0
    for duration in note_durations:
        timestamps_16th.append(total_dur)
        total_dur = total_dur + duration*4

durations_to_timestamps()

print(timestamps_16th)

for timestamp in timestamps_16th:
    timestamps.append(timestamp * beat_16th_duration)

print(timestamps)

timestamp = timestamps.pop(0)
startTime = time.time()

while True:
    currentTime = time.time()
    if (currentTime - startTime >= timestamp):
        kick.play()

        if timestamps:
            timestamp = timestamps.pop(0)
        else:
            break
    else:
        time.sleep(0.001)
 
time.sleep(1)







# sequence = []
# while sum(sequence) < beats_16th_total:
#     sequence.append(int(input()))
#     print(sequence)



# beats_16th = 

# while beats_16th < beats_16th_total



# # shorten list
# sequence = sequence[:beats_16th_total]
# print(len(sequence))



# note16th = BPM/60/4 



# sequence_dur = []

# for i in range(sequence_length):
#     sequence_dur.append(int(input()))

# for index, interval in enumerate(sequence_dur):
#     timeIntervals[index] = interval/BPM



# print(sequence_dur)


# def durationsToTimestamps16th():



