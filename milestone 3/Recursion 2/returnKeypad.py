def keypad(no):

    arr = ["", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
    if(no == 0):
        lst = [""]
        return lst

    small = no //10
    r = no%10
    lst = keypad(small)

    lst_len = len(lst)
    arr_len = len(arr[r])
    
    lst = lst * arr_len
    k = 0

    for i in range(0,arr_len):
        for j in range(0,lst_len):
            lst[k] = lst[k]+arr[r][i]
            k+=1
    return lst

n = int(input())
lst = keypad(n)
for i in lst:
    print(i)