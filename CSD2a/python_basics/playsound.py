import pygame
import time

pygame.mixer.init()

soundfile = pygame.mixer.Sound("sounds/kick.wav")

soundfile.play()
print("Sound played")

for x in range(10):
    soundfile.play()
    print("Sound played")
    time.sleep(1)