import random
import time
import sys

random.seed(time.time())

cnt = sys.argv[1]
file = sys.argv[2]

f = open(file, "w")
for i in range(1,int(cnt)):
    f.write(str(random.randint(0,2**31-1))+"\n")

f.close()
