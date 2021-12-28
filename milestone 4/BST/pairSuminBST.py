import queue
import sys
class BinaryTreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def buildLevelTree(levelorder):
    index = 0
    length = len(levelorder)
    if length<=0 or levelorder[0]==-1:
        return None
    root = BinaryTreeNode(levelorder[index])
    index += 1
    q = queue.Queue()
    q.put(root)
    while not q.empty():
        currentNode = q.get()
        leftChild = levelorder[index]
        index += 1
        if leftChild != -1:
            leftNode = BinaryTreeNode(leftChild)
            currentNode.left =leftNode
            q.put(leftNode)
        rightChild = levelorder[index]
        index += 1
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

def printNodesSumToS(root,sum):
    if root == None:
        return -1

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
levelOrder = [int(i) for i in input().strip().split()]
root = buildLevelTree(levelOrder)
s=int(input())
printNodesSumToS(root,s)