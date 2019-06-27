#import random
def insertRecurciveAtIndex(list, index, value):
     nlist = []
     if (index == 0):
          nlist.append(value)
     if (index < 0):
          return nlist + list
     nlist.append(list[0])
     return nlist + insertRecurciveAtIndex(list[1:],index - 1,value)

xlist =  input('Enter list: ').split(sep=' ') #[random.randint(-10,10) for _ in range(10)]
print(xlist)
print(insertRecurciveAtIndex(xlist, input('Insert value at index: '), 1000)); #cast to int if generator used
