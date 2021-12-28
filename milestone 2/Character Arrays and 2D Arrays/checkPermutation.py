
from sys import stdin


def isPermutation(string1, string2) :
    lst1= list(string1)
    lst2= list(string2)

    lst1.sort()
    lst2.sort()

    # print(lst1)
    # print(lst2)
    if(lst1 == lst2):
        return True
    else:
        return False






#main
string1 = stdin.readline().strip();
string2 = stdin.readline().strip();

ans = isPermutation(string1, string2)

if ans :
    print('true')
else :
    print('false')

