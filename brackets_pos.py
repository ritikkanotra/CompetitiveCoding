brack_inp = input()
# brack_inp = "[][]["

open_brac = ['{','[','(']
close_brac = ['}',']',')']

brac_dict = {')':'(',
            ']':'[',
            '}':'{'}

x = y = z = 0
stack = []

if brack_inp[0] in close_brac:
    print(1)

else:
    for i in range(len(brack_inp)):
        if brack_inp[i] in open_brac:
            stack.append(brack_inp[i])
            count = i+2
        else:
            if (len(stack) == 0 and (brack_inp[i] in close_brac)):
                print(i+1)
                z = 1
                break
            else:
                if brac_dict[brack_inp[i]]== stack[len(stack)-1]:
                    stack.pop()

                else:
                    print(i+1)
                    x = 1
                    break

    if len(stack) == 0 and z == 0:
        print(0)
        y = 1
    if x==0 and y== 0 and z==0:
        print(count)