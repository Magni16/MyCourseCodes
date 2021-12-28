## Read input as specified in the question.
## Print output as specified in the question.
lst = input().split()
lst2=lst[2::]

rows = int(lst[0])
cols = int(lst[1])
# print(rows)
# print(cols)
arr = [int(x) for x  in lst2]
# print(arr)

colSum = 0
colSum2 = 0
lst =[]
k=0
while k< cols:
    for i in range(k,len(arr),cols):
        colSum+=arr[i]
    lst.append(colSum)
    # for i in range(1,len(arr),cols):
    #     colSum2+=arr[i]
    # lst.append(colSum2)
    colSum = 0
    k+=1
print(*lst , sep=" ")
