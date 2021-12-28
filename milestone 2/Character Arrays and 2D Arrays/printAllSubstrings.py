
from sys import stdin


def printSubstrings(string) :
    output=""
    k = 0
    while k<len(string):
        st = string[k::]
        for i in range(len(st)):
            output+=st[i]
            print(output)
        output=""
        k+=1

        


#main
string = stdin.readline().strip();
printSubstrings(string)