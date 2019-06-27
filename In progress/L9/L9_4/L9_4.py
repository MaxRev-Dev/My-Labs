
def printNegativeRecursive(list):
    if (len(list)>0):
        if (list[0] < 0):
            print(list[0])
        printNegativeRecursive(list[1:])

list = [int(x) for x in input('Enter list: ').split(sep=' ')] #[-1,5,6,-87,-6,-7,0,453]
printNegativeRecursive(list)