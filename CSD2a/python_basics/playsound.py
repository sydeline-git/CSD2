import pygame
import time

#intializing mixer
pygame.mixer.init()

#asking for sound repetition value
times = int(input("Please enter amount of times to play the sound: \n"))

#loading sound file
soundfile = pygame.mixer.Sound("sounds/kick.wav")

#playing sound for asked times
for x in range(times):
    soundfile.play()
    print("Sound played")
    time.sleep(1)