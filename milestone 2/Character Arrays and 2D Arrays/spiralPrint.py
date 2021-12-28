from sys import stdin

def spiralPrint(arr,i,j, m, n):

	if (i >= m or j >= n):
		return

	# Print First Row
	for p in range(i, n):
		print(arr[i][p], end=" ")

	# Print Last Column
	for p in range(i + 1, m):
		print(arr[p][n - 1], end=" ")

	# Print Last Row, if Last and First Row are not same
	if ((m - 1) != i):
		for p in range(n - 2, j - 1, -1):
			print(arr[m - 1][p], end=" ")

	# Print First Column, if Last and First Column are not same
	if ((n - 1) != j):
		for p in range(m - 2, i, -1):
			print(arr[p][j], end=" ")

	spiralPrint(arr, i + 1, j + 1, m - 1, n - 1)








def take2DInput() :
    li = stdin.readline().rstrip().split(" ")
    nRows = int(li[0])
    mCols = int(li[1])
    
    if nRows == 0 :
        return list(), 0, 0
    
    mat = [list(map(int, input().strip().split(" "))) for row in range(nRows)]
    return mat, nRows, mCols


#main
t = int(stdin.readline().rstrip())

while t > 0 :

    mat, nRows, mCols = take2DInput()
    spiralPrint(mat,0,0, nRows, mCols)
    print()

    t -= 1