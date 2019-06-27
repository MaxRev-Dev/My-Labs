 
def sum(N):
    return N if (N==0) else N + sum(N-1)
     
while 1:
   try:
      print(sum(int(input('Enter N (max 987): '))))
   except ValueError:
       pass
   except:
       print('too deep stack')
       pass