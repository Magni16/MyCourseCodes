
from sys import stdin

def findTriplet(arr, n, x) :
    numTriplets = 0 
    for i in range(n-2) : 
        for j in range((i + 1), n-1) :
            for k in range((j + 1), n) : 
                if (arr[i] + arr[j] + arr[k]) == x :
                    numTriplets += 1 
    return numTriplets
    #Your code goes here
    #return your answer







#Taking Input Using Fast I/O
def takeInput() :
    n = int(stdin.readline().strip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n



#main
t = int(stdin.readline().strip())

while t > 0 :

    arr, n = takeInput()
    x = int(stdin.readline().strip())
    print(findTriplet(arr, n, x))
    t -= 1