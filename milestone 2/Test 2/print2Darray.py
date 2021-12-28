m,n =input().split()
m = int(m)
n = int(n)
lst=[]
newlst=[]
for i in range(m):
    lst.append(input().split())

newlst =   [list( map(int,i) ) for i in lst] 


i=0
while i<m:
    k = m-i
    while k > 0:
        print(*newlst[i], sep = " ")
        k-=1
    i+=1