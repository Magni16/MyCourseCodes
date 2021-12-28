## Read input as specified in the question.
## Print output as specified in the question.
S=input()
ans=""
for i in range(len(S)):
    if i==len(S)-1:
        ans+=S[i]
        break
    if S[i]==S[i+1]:
    	ans+=S[i]+"*"
    else:
        ans+=S[i]
print(ans)
    