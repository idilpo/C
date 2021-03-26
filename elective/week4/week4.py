from random import randint
distance = []

def average(list):
    return sum(list)/len(list)

for i in range(0, 10000):
    number1 = randint(0,101)
    number2 = randint(0,101)

    if number1 > number2:
        difference = number1 - number2
        distance.append(difference)
    elif number2 > number1:
        difference = number2 - number1
        distance.append(difference)
    else:
        distance.append(0)

print(average(distance))