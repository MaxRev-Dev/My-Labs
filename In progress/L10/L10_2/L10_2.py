
def commaPrint(func):
    def print_wrap(*args, **kwargs):  
       print( args, sep=',')
    return print_wrap
 


printN = commaPrint(print);
lst1  = input('Enter word: ')
lst2 = input('Enter word: ')
print(lst1,lst2)
printN(lst1,lst2) 