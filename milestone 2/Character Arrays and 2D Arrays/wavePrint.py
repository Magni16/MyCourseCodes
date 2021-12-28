from sys import stdin

def wavePrint(arr, nRows, mCols):
    ans = []
    #Loop to iterate through the columns given to us.
    for j in range(mCols):
        
        # If the current column is even then we will add the elements from top to bottom.
        if j % 2 == 0: 
            for i in range(nRows):
                ans.append(arr[i][j])
        else:
            for i in range(nRows - 1, -1, -1):
                ans.append(arr[i][j])           
    print(*ans ,sep =" ")




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
    wavePrint(mat, nRows, mCols)
    print()

    t -= 1