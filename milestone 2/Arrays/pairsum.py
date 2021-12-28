
from sys import stdin


def pairSum(arr, n, x) :
    #Your code goes here
    lst=[]
    for i in range(len(arr)):
        for j in arr[i+1::]:
            q=(x - arr[i])
            if (j == q):
                lst.append((arr[i],q))
                continue
    count = len(lst)
    
    return len(lst)




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
    print(pairSum(arr, n, x))

    t -= 1