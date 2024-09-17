import pygame
import time

#intializing mixer
pygame.mixer.init()

#asking for sound repetition value
num_times = int(input("Please enter the amount of times to play the sound for: \n"))

#how many times to repeat


#loading sound file
soundfile = pygame.mixer.Sound("sounds/kick.wav")

#playing sound for asked times
for x in range(num_times):
    soundfile.play()
    print("Sound played")
    time.sleep(1)