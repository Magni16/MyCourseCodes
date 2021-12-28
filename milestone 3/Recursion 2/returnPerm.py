def permute(s):
    lst=[]
    length = len(s)
    if length ==1:
        return [s]
    for i in range(0,length):
        perms = permute(s[0:i]+s[i+1:])
        for perm in perms:
            lst.append(s[i] + perm)       
    return lst

n = input()
perms = permute(n)
print(*perms , sep = '\n')