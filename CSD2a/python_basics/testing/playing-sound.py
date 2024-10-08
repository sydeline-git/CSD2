
sequence_inputs = 0

sequence_length = 16

sequence = []

while sequence_inputs < sequence_length:

    input = int(input("Input"))

    sequence_append(1)

    sequence_inputs = sequence_inputs + input




    sequence_inputs_left = sequence_length - sequence_inputs


import time
import pygame

pygame.mixer.init()

BPM = 120

#   asking user the length of the sequence and making a list of zeros

sequence = []

sequence_inputs = [0]

sequence_length = int(input("How many 16th notes should the sequence consist of?"))

for beats in range(sequence_length):
    sequence.append(0)

print(sequence)





#   getting the length of the individual 16th notes
print("Enter the length of the individual 16th notes")
while sum(sequence_inputs) < sequence_length:
    sequence_inputs.append(int(input()))

#als sum hoger is dan sequence length haal verschil af van laatste inputs

print(sequence_inputs)

sum_inputs = 0

for inputs in range(len(sequence_inputs)):
    sum_inputs += inputs 
    sequence_inputs[inputs] = sum_inputs
print(sequence_inputs)




# def event_handler():
