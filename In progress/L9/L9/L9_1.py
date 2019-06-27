 
def checkNum():
    num = int(input('Enter number: '))
    if (num % 3 == 0):
       print('Yep')
       # success, but here we can call func again
       # checkNum() 
    else:
       print('Try again')
       checkNum()

checkNum()