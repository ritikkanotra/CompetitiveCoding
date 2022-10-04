for _ in range(int(input())):
    n = int(input())
    if n%2 == 0:
        for i in range(n//2):
            n = n//2
            if n%2 !=0:
                break
    print(n//2)
