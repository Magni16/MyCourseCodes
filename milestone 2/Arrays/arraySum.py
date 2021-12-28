## Read input as specified in the question.
## Print output as specified in the question.
lst = []
n = int(input())
k = input()
lst = k.split()

lst1 = [int(x) for x in lst]
print(sum(lst1))
