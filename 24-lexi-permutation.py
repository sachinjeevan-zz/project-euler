import math

x = 999999
for i in range(9, 0, -1):
    j = 0
    f = math.factorial(i)
    while x >= f:
        j += 1
        x -= f
    print "%d! * %d" % (i, j)
