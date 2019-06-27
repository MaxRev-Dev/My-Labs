
list = input('Enter list: ').split(sep=' ')# range(-10,10,1)

def printList(list):
    return '[' + ", ".join(str(i) for i in list) + ']'

print(printList(list))

def conv(list):
    for index in range(len(list) - 1, -1, -1):
        yield list[index] 


print(printList(conv(list)))
        