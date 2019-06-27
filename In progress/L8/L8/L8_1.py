
list_obj = input('Enter list: ').split(sep=' ')  #range(-10,10,1)

def printList(list):
    return '[' + ", ".join(str(i) for i in list) + ']'

class RevList: 
    def __init__(self, list):
        self.list = list

    def __iter__(self): 
        self.index = len(self.list)
        return self

    def __next__(self):    
        self.index -= 1
        if (self.index > -1):
            return self.list[self.index]
        else:
            raise StopIteration

    def __repr__(self):
        return printList(self)

    def clear(self):
        self.list = []

    def insertAt(self, index, value):
        if (index>=0 and index<=len(self.list)):
            self.list.insert(len(self.list) - index,value);
        else: 
            raise Exception("range not satisfiable")
    def deleteAt(self, index, value):
        if (index>=0 and index<=len(self.list)):
            del self.list[len(self.list) - index];
        else: 
            raise Exception("range not satisfiable")
    def deleteAt(self,index):
        del self.list[index] 
    def deleteFirst(self):
        self.deleteAt(len(self.list)-1)
    def deleteLast(self):
        self.deleteAt(0)

print(printList(list_obj))
rvl = RevList(list(list_obj))
print(printList(rvl))
#rvl.insertAt(3,1000);
#rvl.insertAt(6,-1000);
#rvl.insertAt(0,-1000);
rvl.insertAt(int(input('Enter index for insertion: ')), input('Enter value: ')); 

print(rvl)

#rvl.deleteAt(0);
rvl.deleteAt(int(input('Enter index for deletion: ')))
print('Deleting last and first values')
rvl.deleteFirst();
rvl.deleteLast();

print(rvl)

rvl.clear()

print(rvl)
