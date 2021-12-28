
from sys import stdin


def reverseEachWord(string) :
    newlst=[]
    lst = string.split()
    for i in lst:
        k=i[::-1]
        newlst.append(k)
    return " ".join(newlst)
    
	# Your code goes here



#main
string = stdin.readline().strip()

ans = reverseEachWord(string)

print(ans)