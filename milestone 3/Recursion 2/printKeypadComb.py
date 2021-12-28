def possibleString(no):
    if no == 2:
        return 'abc'
    elif no == 3:
        return 'def'
    elif no == 4:
        return 'ghi'
    elif no == 5:
        return 'jkl'
    elif no == 6:
        return 'mno'
    elif no == 7:
        return 'pqrs'
    elif no ==8:
        return 'tuv'
    elif no == 9:
        return 'wxyz'
    else:
        return ''

# my helper function taking empty string initially
def printKeypadHelper(n,newstr):
    if n==0:
        print(newstr)
        return

    st = possibleString(n%10)
    
    for i in st:
        printKeypadHelper(n//10, i+newstr)
    
def printKeypad(n):
    printKeypadHelper(n,'')

n = int(input().strip())
printKeypad(n)