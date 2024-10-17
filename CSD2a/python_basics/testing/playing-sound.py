#------ GETTING USER INPUTS ------#
def time_signature_to_16th_notes(numerator, denominator):
    slice_length = numerator * (16 / denominator)
    return slice_length


def get_time_signature():
    time_signature = input('Please enter the time signature of your sequence in the following format "_/_". \n')
    
    try:
        numerator, denominator = map(int, time_signature.split('/'))
        return numerator, denominator
    
    except ValueError:
        print('Input invalid! Please enter the time signature in the before mentioned format.')
        return get_time_signature()


def get_measures():
    try:
        measures = int(input('How many measures should the sequence consist of? \n'))

    except ValueError:
        print('Please enter a valid integer')
        return get_measures()

    return measures

def get_text(slice_length):
    text_minimum = int(slice_length / 8)
    print('Input your text:')

    while True:
        text = input()
        
        if len(text) < text_minimum:
            print('Input your text with a minimum of', text_minimum, 'charachters please.')
        else:
            return text
            
            
def get_inputs():
    numerator, denominator = get_time_signature()
    slice_length = get_measures() * time_signature_to_16th_notes(numerator, denominator)
    get_text(slice_length)

    return slice_length

slice_length = int(get_inputs())







# import random

# slice_length = 8

# list = [0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1]

# slice_start = random.randrange(len(list) - slice_length)

# print(slice_start)

# new_list = []

# def slicer(slice_length, list):
#     slice_start = random.randrange(len(list) - slice_length)

#     for _ in range(slice_length):
#         new_list.append(list.pop(slice_start))

    
 
# slicer(slice_length, list)

# print(new_list)



# import random
# import time


# def random_binary():
#     return int(random.random() >= 0.5)
    

# bit = random_binary()

# print(bit)


# # sequence_inputs = 0

# # sequence_length = 16

# # sequence = []

# # while sequence_inputs < sequence_length:

# #     input = int(input("Input"))

# #     sequence_append(1)

# #     sequence_inputs = sequence_inputs + input




# #     sequence_inputs_left = sequence_length - sequence_inputs


# # import time
# # import pygame

# # pygame.mixer.init()

# # BPM = 120

# # #   asking user the length of the sequence and making a list of zeros

# # sequence = []

# # sequence_inputs = [0]

# # sequence_length = int(input("How many 16th notes should the sequence consist of?"))

# # for beats in range(sequence_length):
# #     sequence.append(0)

# # print(sequence)





# # #   getting the length of the individual 16th notes
# # print("Enter the length of the individual 16th notes")
# # while sum(sequence_inputs) < sequence_length:
# #     sequence_inputs.append(int(input()))

# # #als sum hoger is dan sequence length haal verschil af van laatste inputs

# # print(sequence_inputs)

# # sum_inputs = 0

# # for inputs in range(len(sequence_inputs)):
# #     sum_inputs += inputs 
# #     sequence_inputs[inputs] = sum_inputs
# # print(sequence_inputs)
