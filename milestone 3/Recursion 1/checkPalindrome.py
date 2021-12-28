## Read input as specified in the question.
## Print output as specified in the question.
S=input()

for i in range(len(S)//2):
    if S[i]!=S[-(i+1)]:
        print("false")
        exit()
print("true")