## Read input as specified in the question.
## Print output as specified in the question.
def helper(arr,mylst):
    # main function to print subset
    n = len(arr)
    if (n==0):
        for no in mylst:
            print(no , end=' ')
        print()
        return
        
    helper(arr[1:],mylst)
    new_mylst = mylst.copy()
    new_mylst.append(arr[0])
    helper(arr[1:],new_mylst)
    return

def printSubset(arr):
    helper(arr,[])
    
n = int(input())
arr = list(int(i) for i in input().strip().split(' '))
printSubset(arr)