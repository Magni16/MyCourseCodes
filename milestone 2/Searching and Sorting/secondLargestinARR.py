# Take Minimum value as MIN_VALUE = -2147483648
from sys import stdin
from collections import Counter

def secondLargestElement(arr, n):
    if len(arr) == 0:
        return -pow(2,31)
    if len(arr)==1:
        return -pow(2,31)
    arr.sort()
    x = arr.pop()
    times = 0
    counter = Counter(arr)
    counter = dict(counter)
    for k,v in counter.items():
        if k == x:
            times = v
    for i in range(times):
        arr.remove(x)
    if(len(arr) == 0):
        return -pow(2,31)
    return arr[-1]

    
        

    





#Taking Input Using Fast I/O
def takeInput() :
    n = int(stdin.readline().rstrip())
    if n != 0:
        arr = list(map(int, stdin.readline().rstrip().split(" ")))
        return arr, n

    return list(), 0



#main
t = int(stdin.readline().rstrip())

while t > 0 : 
    
    arr, n = takeInput()
    print(secondLargestElement(arr, n))

    t -= 1