import pygame
import time

#startup mixer
pygame.mixer.init()

#import sound
sound = pygame.mixer.Sound("kick.wav") 

BPM = int(input("What BPM?: \n"))

#create list
myList = [] 

print(myList)

#add values to list
myList.append(0.5)    
myList.append(1)
myList.append(0.5)
myList.append(1)
myList.append(1)

#print list
print("List", myList, "Lenght of list", len(myList))

times = int(input("How many times to repeat?: \n"))

#play sounds according to list
for i in range(times):
    for delay in myList:
        print("Jeff",delay)
        sound.play()
        time.sleep(delay)
    

