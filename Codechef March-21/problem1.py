for _ in range(int(input())):
    n = int(input())
    arr_c = []

    for i in reversed(range(n)):
        for j in range(n//2, n):
            if i^j == n:
                print(i,"   i  <-->  j  ",j)
                arr_c.append(i*j)
    print(arr_c)        
    print(max(arr_c))