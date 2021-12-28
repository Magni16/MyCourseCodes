
from sys import stdin


def binarySearch(arr, l,r, x) :

    if r >= l:
 
        mid = l + (r - l) // 2
 
        if arr[mid] == x:
            return mid
 
        elif arr[mid] > x:
            return binarySearch(arr, l, mid-1, x)
 
        else:
            return binarySearch(arr, mid + 1, r, x)
 
    else:
        return -1


def takeInput() :
    n = int(stdin.readline().strip())
    
    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n


#main
arr, n = takeInput()
t = int(stdin.readline().strip())

while t > 0 :
    l=0
    r=n-1
    x = int(input().strip())    
    print(binarySearch(arr, l,r, x))

    t -= 1