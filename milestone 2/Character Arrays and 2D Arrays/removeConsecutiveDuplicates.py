
from sys import stdin

def removeConsecutiveDuplicates(s) :
      seen = s[0]
      ans = s[0]
      for i in s[1:]:
         if i != seen:
            ans += i
            seen = i
      return ans



























	


#main
string = stdin.readline().strip()

ans = removeConsecutiveDuplicates(string)

print(ans)