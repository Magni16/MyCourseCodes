## Read input as specified in the question.
## Print output as specified in the question.
def printpermute(s, output):
    length = len(s)
    if length == 0:
        print(output)
        return
    for i in range(0,length):
        printpermute(s[0:i]+s[i+1:],s[i]+ output)
        
def permute_main(s):
	printpermute(s,"")
            
s = input()
permute_main(s)