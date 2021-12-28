n =input()
x= len(n.split())
lst=[]
lst.append(n.split())
maxi = 9999999

arr=[]
for i in lst:
    for j in i:
        arr.append(j)


for ele in arr:
    maxi = min(maxi,len(ele))

for i in arr:
    if len(i) ==maxi:
        print(i)
        break
