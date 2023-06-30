import random
import time
import sys

random.seed(time.time())

cnt = sys.argv[1]
file = sys.argv[2]

# Create an ordered list of random integers
data_list = []  # type: list[int]
for i in range(0,int(cnt)):
    data_list.append(random.randint(0,2**32-1))
data_list = sorted(data_list)  # Sort data_list

# Select a random element from this list
selected = random.choice(data_list)

# Write everything to a file, 1st line is element to be searched
f = open(file, "w")
f.write(str(selected)+"\n")
for elem in data_list:
    f.write(str(elem)+"\n")
f.close()
