## Read input as specified in the question.
## Print output as specified in the question.
# Problem ID 328 Midpoint LL
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None



def nextNumber(head):
    #Implement Your Code here
    temp =head
    lst =[]
    stri = ""
    while temp != None:
        lst.append(temp.data)
        temp = temp.next
    # lst.append(temp.data)
    
    for i in lst:
        stri+=str(i)
    
    val = int(stri)
    val+=1
    newstr  = str(val)
    lst2=[int(i) for i in newstr]

    curr = dummy = Node(0)
    for i in lst2:
        curr.next = Node(i)
        curr = curr.next
    return dummy.next

        
    
    pass
        
def ll(arr):
    if len(arr)==0:
        return None
    head = Node(arr[0])
    last = head
    for data in arr[1:]:
        last.next = Node(data)
        last = last.next
    return head

def printll(head):
    while head is not None:
        print(head.data,end= ' ')
        head = head.next
    return

# Main
# Read the link list elements including -1
arr=[int(ele) for ele in input().split()]
# Create a Linked list after removing -1 from list
l = ll(arr[:-1])
head = nextNumber(l)
printll(head)