from collections import Counter
from sys import stdin


def highestOccuringChar(str) :
	ASCII_SIZE = 256

	count = [0] * ASCII_SIZE

	# Utility variables
	max = -1
	c = ''
	for i in str:
		count[ord(i)]+=1;

	for i in str:
		if max < count[ord(i)]:
			max = count[ord(i)]
			c = i

	return c



#main
string = stdin.readline().strip();
ans = highestOccuringChar(string)

print(ans)