import math

x_l = int(input())
y_l = int(input())
x_w = int(input())
y_w = int(input())
flt = float(input())

if (y_l+y_w)==0:
    a = x_l*flt

print("{0:.6f}".format(math.floor(a)))