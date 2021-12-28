def stairCase(n):
    if ( n == 0 ):
        return 1
    elif (n < 0):
        return 0
    else:
        return stairCase(n - 3) + stairCase(n - 2) + stairCase(n - 1)




# main

n = int(input())
answer = stairCase(n)
print(answer)