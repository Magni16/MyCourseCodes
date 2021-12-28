# Problem: Remove x from string
def removeX(string):
    counter=Counter(string)
    counter=dict(counter)
    myval=0
    lst=list(string)

    for k,v in counter.items():
        if k=="x":
            myval=v
    for i in range(myval):
        lst.remove("x")
    return "".join(lst)
    
 	

# Main
from collections import Counter
string = input()
print(removeX(string))
