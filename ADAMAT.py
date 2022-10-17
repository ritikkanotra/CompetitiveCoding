


for tc in range(int(input())):
    mat_list = []
    count = 0

    #length of N*N Matrix
    N = int(input())
    for iterator in range(N):
        #NxN Matrix 
        arr_n = [int(x) for x in input().split()]
        mat_list.append(arr_n)
    for idx in range(N-1,0,-1):
        check = mat_list[idx][idx-1] + 1
        if check!=mat_list[idx][idx]:
            count += 1
            check1 = idx+1
            for i in range(check1):
                #Swapping with L1/L2/L3/L4
                for j in range(i, check1):
                    mat_list[j][i], mat_list[i][j] = mat_list[i][j],mat_list[j][i]
    print(count)