
from sys import stdin

def arrayRotateCheck(arr, n):

 
    # We basically find index
    # of minimum element
    if n ==0:
        return 0
    min = arr[0]
    min_index = 0
    for i in range(0, n):
     
        if (min > arr[i]):
         
            min = arr[i]
            min_index = i
         
    return min_index;
    #Your code goes here










#Taking Input Using Fast I/O
def takeInput() :
    n = int(stdin.readline().rstrip())
    if n == 0:
        return list(), 0

    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    return arr, n


#main
t = int(stdin.readline().rstrip())

while t > 0 :

    arr, n = takeInput()
    print(arrayRotateCheck(arr, n))

    t -= 1