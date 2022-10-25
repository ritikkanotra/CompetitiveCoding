
class Solution:
    def MinNumber(self, arr):
        curr_max = 0
        last_val = 0
        i = 0
        while i < len(arr):
            total_next_D = 0
            if arr[i] == "I":
                j = i + 1
                while j < len(arr) and arr[j] == "D":
                    total_next_D += 1
                    j += 1
                if i == 0:
                    curr_max = total_next_D + 2
                    last_val += 1
                    print(last_val, end = "")
                    print(curr_max, end = "")
                    last_val = curr_max
                else:
                    curr_max += total_next_D + 1
                    last_val = curr_max
                    print(last_val, end = "")
                for k in range(total_next_D):
                    last_val -= 1
                    print(last_val, end = "")
                    i += 1
            elif arr[i] == "D":
                if i == 0:
                    j = i + 1
                    while j < len(arr) and arr[j] == "D":
                        total_next_D += 1
                        j += 1
                    curr_max = total_next_D + 2
                    print(curr_max, curr_max - 1, end = "")
                    last_val = curr_max - 1
                else:
                    print(last_val - 1, end = "")
                    last_val -= 1
            i += 1


string = input()
Solution().MinNumber(string)