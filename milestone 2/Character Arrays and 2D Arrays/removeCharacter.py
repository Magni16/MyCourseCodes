
from sys import stdin


def removeAllOccurrencesOfChar(string, ch) :
    s3 = string.replace(ch,"")
    return s3


	

#main
string = stdin.readline().strip()
ch = stdin.readline().strip()[0]

ans = removeAllOccurrencesOfChar(string, ch)

print(ans)