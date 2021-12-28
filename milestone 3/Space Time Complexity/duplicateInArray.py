from sys import stdin
from collections import Counter

def findDuplicate(arr, n) :
    counter = Counter(arr)
    counter = dict(counter)
    
    for k,v in counter.items():
        if v==2:
            return k
        
    #Your code goes here




























    



#Taking input using fast I/O method
def takeInput() :
    n = int(stdin.readline().rstrip())

    if n == 0 :
        return list(), 0

    arr = list(map(int, stdin.readline().rstrip().split(" ")))
    return arr, n


#main
t = int(stdin.readline().rstrip()) 

while t > 0 :

    arr, n = takeInput()
    print(findDuplicate(arr, n))

    t -= 1