
from sys import stdin, setrecursionlimit
setrecursionlimit(10**5)

#Following is the Node class already written for the Linked List
class Node :
    def __init__(self, data) :
        self.data = data
        self.next = None


def palindrome(arr, n):
 
    flag = 0
 
    i = 0
    while (i <= n // 2 and n != 0):

        if (arr[i] != arr[n - i - 1]):
            flag = 1
            break
        i += 1

    if (flag == 1):
        return False
    else:
        return True


def isPalindrome(head) :
    
    if head == None:
        return True
    
    temp = head
    arr = []
    while temp.next != None:
        arr.append(temp.data)
        temp = temp.next
    arr.append(temp.data)
    # print(*arr)

    # flag = False
    # flag = palindrome(arr , len(arr))
    # return flag
    flag = False
    if arr[::]== arr[::-1]:
        flag = True
    else:
        flag = False
    return flag
        
        






#Taking Input Using Fast I/O
def takeInput() :
    head = None
    tail = None

    datas = list(map(int, stdin.readline().rstrip().split(" ")))

    i = 0
    while (i < len(datas)) and (datas[i] != -1) :
        data = datas[i]
        newNode = Node(data)

        if head is None :
            head = newNode
            tail = newNode

        else :
            tail.next = newNode
            tail = newNode

        i += 1

    return head


#to print the linked list 
def printLinkedList(head) :

    while head is not None :
        print(head.data, end = " ")
        head = head.next

    print()




#main
t = int(stdin.readline().rstrip())

while t > 0 :
    
    head = takeInput()
    
    if isPalindrome(head) :
        print('true')
    else :
        print('false')

        
    t -= 1