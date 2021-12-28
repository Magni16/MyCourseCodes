import sys
sys.setrecursionlimit(10 ** 8)

def helper(arr , si , k):
    if si == len(arr):
        if k==0:
            return [list()]

        else:
            return list()

    small_output1= helper(arr, si+1 , k)
    small_output2 = helper(arr , si+1 ,k - arr[si])
    output = (len(small_output1)+len(small_output2))*[0]

    index = 0
    for i in range(len(small_output1)):
        output[index] = small_output1[i]
        index+=1

    for i in range(len(small_output2)):
        output[index] = (len(small_output2[i])+1)*[0]
        output[index][0] = arr[si]

        for j in range(len(small_output2[i])):
            output[index][j+1] = small_output2[i][j]
        index+=1
        
    return output

def subsetsSumK(arr , k):
    return helper(arr, 0 ,k)

#taking input
def takeInput() :
    n = int(input().strip())

    if n == 0 :
        return list(), 0

    arr = [int(element) for element in list(input().strip().split(" "))]
    return arr, n


#printing the list of lists
def printListOfList(liOfLi) :
    for li in liOfLi :
        for elem in li :
            print(elem, end = " ")
        print()

#main
arr, n = takeInput()

if n != 0 :
    k = int(input().strip())
    liOfLi = subsetsSumK(arr, k)

    printListOfList(liOfLi)

