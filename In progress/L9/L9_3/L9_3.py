 
def checkPos(a, b):
   if (a == 0):
       return 1 # all => 1
   if (a==1):
       return b+1 # 1 => zero - other => 1
   if (a>1 and b==0): # zeros > 1 and no 1
       return 0
   return checkPos(a - 1, b - 1) + checkPos(a, b - 1)

while 1:
    print('Result: '+ checkPos(int(input('Enter a: ')), int(input('Enter b: ')))) 

