import pygame
import time

#initializing sound and player
pygame.mixer.init()
kick = pygame.mixer.Sound("sounds/kick.wav")
snare = pygame.mixer.Sound("sounds/snare.wav")
hihat = pygame.mixer.Sound("sounds/hihat.wav")

#ask for what sample
while True:
    sound = input("What sample would you like to use? kick, snare or hihat'? \n") 

    if sound in ['kick', 'snare', 'hihat']:
        print(sound, "chosen as sample")
        break
    else:
        print("Please enter a valid input") 

#ask for the amount of times to play the sample for
while True:
    try:
        numPlaybackTimes = int(input("How many times would you like to play the sample for?: \n"))
    except ValueError: 
        print("Pease enter a valid integer")
        continue
    break

#creation of playback list for different time intervals
while True:
    try:
        print("Please enter the different intervals for the amount of times the sample is played for:")
        playbackList = []
        for i in range(numPlaybackTimes):
            playbackList.append(float(input()))
    except ValueError:
        print("Please enter a valid integer")
        continue
    break

#ask for playback speed in BPM
while True:
    try:
        BPM = int(input("What BPM would you like to play it back for?: \n"))/60
        print("BPM of", BPM, "confirmed")
    except ValueError:
        BPM = 2
        print("BPM set to 120")
    break

#repeats
while True:
    try:
        numRepeats = int(input("Please enter the amount of times to repeat the rhythm \n"))
        print("The rhythm will repeat for", numRepeats, "amount of times")
    except ValueError:
        print("Please enter a valid integer")
        continue
    break


#playing the sounds according to list
for repeats in range(numRepeats):
    for i in range(numPlaybackTimes):
        if sound == 'kick': 
            kick.play()
        elif sound == 'snare':
            snare.play()
        elif sound == 'hihat':
            hihat.play()

        time.sleep(playbackList[i]/BPM)
        print(playbackList[i], sound)   
    print("Repeat ", repeats + 1)         

print("Files played")

