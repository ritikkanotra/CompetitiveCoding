for _ in range(int(input())):
    n = int(input())
    v = [int(x) for x in input().split()]
    max_target = max(v)
    diff_target = 0
    print(max_target)
    for i in range(n):
        diff_target += (max_target - v[i])
    
    if diff_target == 0 or diff_target%2 == 1:
        print("First")
    else:
        print("Second")
        