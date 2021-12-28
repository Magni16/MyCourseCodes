
import sys

def intersections(arr1, n, arr2, m) :
    #Your code goes here
    # Python program to illustrate the intersection
    # of two lists in most simple way

    i,j=0,0
    lst=[]
    var = -99999999
    for i in range(len(arr1)):
        for j in range(len(arr2)):
            if arr1[i] == arr2[j]:
                lst.append(arr1[i])
                arr2[j] = var
                break

        
        

    print(*lst,sep=" ")






#Taking Input Using Fast I/O
def takeInput() :
    n = int(sys.stdin.readline().strip())
    if n == 0:
        return list(), 0

    arr = list(map(int, sys.stdin.readline().strip().split(" ")))
    return arr, n


#main
t = int(sys.stdin.readline().strip())

while t > 0 :
    arr1, n = takeInput()
    arr2, m = takeInput()

    intersections(arr1, n, arr2, m)
    print()

    t -= 1