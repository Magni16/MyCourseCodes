## Read input as specified in the question.
## Print output as specified in the question.
def helper(arr,ele, lst):
    n = len(arr)
    if n==0:
        return
    if n ==1:
        if arr[0] == ele:
            print(ele,*lst)
            return
    helper(arr[:-1],ele,lst)
    helper(arr[:-1],ele-arr[-1],[arr[-1]]+lst)
    if arr[-1] == ele:
        print(ele, *lst)

def printSubset(arr,ele):
    helper(arr,ele,[])

n = int(input())
arr = list(int(i) for i in input().strip().split(' '))
ele = int(input())
printSubset(arr,ele)