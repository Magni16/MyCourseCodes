## Read input as specified in the question.
## Print output as specified in the question.
S=input()
ans=""
i=0
while i<len(S):

    if S[i]=='p' and i==len(S)-1:
        ans+='p'
        break
        
    if S[i]=='p' and S[i+1]=='i':
        ans+="3.14"
        i+=2
    
    else:
        ans+=S[i]
        i+=1
print(ans)
        