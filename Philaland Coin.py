

for _ in range(int(input())):
    num = int(input())
    count = 0
    while num>=1:
        num = num//2
        count +=1
    print(count)