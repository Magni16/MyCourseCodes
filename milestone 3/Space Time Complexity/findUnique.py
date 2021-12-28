from sys import stdin
from collections import Counter

def findUnique(arr, n) :
    counter = Counter(arr)
    counter = dict(counter)
    
    for k,v in counter.items():
        if v==1:
            return k
    #Your code goes here




























#taking input using fast I/O method
def takeInput() :
    n = int(stdin.readline().strip())
    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().strip().split(" ")))
    return arr, n


def printList(arr, n) : 
    for i in range(n) :
        print(arr[i], end = " ")
    print()


#main
t = int(stdin.readline().strip())

while t > 0 :
    
    arr, n = takeInput()
    print(findUnique(arr, n))

    t-= 1