s =input()
k = s.split()
k1 = k[::-1]
newstr =""
for i in k1:
    newstr+=i
    newstr+=" "
print(newstr)