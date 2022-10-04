# ---------------- MAXFUN -----------------
# SHANTANU GUPTA
# PSIT - BTECH - CS
# @SHANTANU1118

for _ in range(int(input())):
    n = int(input())
    list_n = [int(x) for x in input().split()]
    res = 0
    list_n.append(list_n[0])
    # print(list_n)
    for i in range(n):
        # print(list_n[i],list_n[i+1])
        res += abs(list_n[i]-list_n[i+1])
    print(res)
