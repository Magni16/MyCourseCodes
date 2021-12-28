
from sys import stdin
def toLowerCase(s):

    str = ""

	# Traverse through the string s
    for i in range(len(s)):

        ch = s[i]

		# Check if ch is a uppercase letter
        if (ch <= 'Z' and ch >= 'A'):
            ch = ord(ch) - (ord('A') - ord('a'))
            ch = chr(ch)

        str = str + ch
	
    return str

# This function reverse the string s
def reverseString(s):

    return s[::-1]
 
def isPalindrome(s) :
    '''
	Time complexity: O((length(S))
	Space Complexity: O((length(S))
	
	Where S is the given string. 
'''


	# Convert uppercase letter into lowercase letter
    s = toLowerCase(s)

	# Find the reverse string of s
    reversedS = reverseString(s)

    n = len(s)
    i = 0
    j = 0

    while (i < n and j < n):

        if (s[i].isalnum() == False):

            # ith pointer points to invalid character.
            i += 1
        
        elif (reversedS[j].isalnum() == False):

            # jth pointer points to invalid character.
            j += 1

        elif (s[i] == reversedS[j]):
            i += 1
            j += 1

        else:
            return False
	
    return True



#main
string = stdin.readline().strip();
ans = isPalindrome(string)

if ans :
    print('true')
else :
    print('false')

