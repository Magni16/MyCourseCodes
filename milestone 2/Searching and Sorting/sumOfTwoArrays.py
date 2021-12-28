def sumArray(arr1,n,arr2,m,output):
    i=n-1
    j=m-1
    carry=0
    l=max(n,m)+1
    while i>=0 and j>=0:
        num=arr1[i]+arr2[j]+carry
        s=num%10
        carry=num//10
        output[l-1]=s
        l=l-1
        i=i-1
        j=j-1
    while i>=0:
        num=arr1[i]+carry
        s=num%10
        carry=num//10
        output[l-1]=s
        l=l-1
        i=i-1
    while j>=0:
        num=arr2[j]+carry
        s=num%10
        carry=num//10
        output[l-1]=s
        l=l-1
        j=j-1
    if carry!=0:
        output[0]=carry
        
    
    
t=int(input())
for i in range(t):
    n=int(input())
    if n==0:
        print(0)
        break
    arr1=[int(x) for x in input().split()]
    m=int(input())
    arr2=[int(x) for x in input().split()]
    size=max(n,m)+1
    output=[0 for i in range(size)]
    sumArray(arr1,n,arr2,m,output)
    print(*output)
    print()