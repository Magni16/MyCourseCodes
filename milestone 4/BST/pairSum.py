from sys import stdin,setrecursionlimit
setrecursionlimit(10**6)
import queue
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

#Taking level-order input using fast I/O method
def takeInput():
    levelOrder = list(map(int, stdin.readline().strip().split(" ")))
    start = 0
    
    length = len(levelOrder)

    if length == 1 :
        return None
    
    root = BinaryTreeNode(levelOrder[start])
    start += 1

    q = queue.Queue()
    q.put(root)

    while not q.empty():
        currentNode = q.get()

        leftChild = levelOrder[start]
        start += 1

        if leftChild != -1:
            leftNode = BinaryTreeNode(leftChild)
            currentNode.left =leftNode
            q.put(leftNode)

        rightChild = levelOrder[start]
        start += 1

        if rightChild != -1:
            rightNode = BinaryTreeNode(rightChild)
            currentNode.right =rightNode
            q.put(rightNode)

    return root

lst=[]
def convertToArr(root):
    lst.append(root.data)
    if root.left != None:
        convertToArr(root.left)
    if root.right != None:
        convertToArr(root.right)
    return lst


def pairSum(root, sum):
    # Write your code here
    arr = convertToArr(root)
    arr.sort()
    # print(arr)
    i = 0
    j = len(arr)-1
    while(i<j):
        if(arr[i] +arr[j] == sum):
            print(arr[i],arr[j])
            i+=1
            j-=1
        elif(arr[i]+arr[j]< sum):
            i+=1
        else:
            j-=1
        




# Main

root = takeInput()
k=int(input())
pairSum(root, k)