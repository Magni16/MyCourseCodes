
num=int(input())
arr= list(map(int,input().split()))
m=0
arr.sort()
for i in arr:
    if m<i*num:
        m=i*num
    num=num-1
print(m)