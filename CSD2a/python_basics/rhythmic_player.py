import pygame
import time

#initializing sound and player
pygame.mixer.init()
kick = pygame.mixer.Sound("sounds/kick.wav")

#user input
numPlaybackTimes = int(input("How many times would you like to play the sample for?: \n"))
print("Please enter the different intervals for the amount of times the sample is played for: \n")

#creation of playback list for different time intervals
playbackList = []
for i in range(numPlaybackTimes):
    playbackList.append(float(input()))

#ask for playback speed in BPM
BPM = int(input("What BPM would you like to play it back for?: \n"))/60

#playing the sounds according to list
for i in range(numPlaybackTimes):
    kick.play()
    time.sleep(playbackList[i]/BPM)

print("Files played")
