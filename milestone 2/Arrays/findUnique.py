import sys
from collections import Counter

def findUnique(arr, n) :
    counter = Counter(arr)
    counter = dict(counter)
    for k,v in counter.items():
        if v ==1:
            return k


#Taking Input Using Fast I/O
def takeInput() :
    n = int(sys.stdin.readline().rstrip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, sys.stdin.readline().rstrip().split(" ")))
    return arr, n


#main
t = int(sys.stdin.readline().rstrip())

while t > 0 :

    arr, n = takeInput()
    print(findUnique(arr, n))

    t -= 1