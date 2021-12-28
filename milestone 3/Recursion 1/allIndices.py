## Read input as specified in the question.
## Print output as specified in the question.
N=int(input())
arr=list(int(i) for i in input().strip().split(' '))
x=int(input())
lst=[]
for i in range(len(arr)):
    
    if arr[i]==x:
        lst.append(i)

for i in range(len(lst)):
    print(lst[i], end=" ")
