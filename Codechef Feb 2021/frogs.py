
import math
for _ in range(int(input())):
    n = int(input())
    weight = [int(x) for x in input().split()]
    lenght = [int(x) for x in input().split()]
    res = 0
    idx = {}
    for i in range(1, n+1):
        idx[i] = weight.index(i)
    for i in range(2, n+1):
        t1 = idx[i]
        t2 = idx[i-1]
        t = 0
        if t1<t2:   t = (math.ceil((t2+1-t1)/lenght[t1]))
        res += t
        idx[i] += t*(lenght[t1])
    print(res)