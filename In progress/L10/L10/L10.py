

num =int( input('Enter number: '))


f = lambda x: list(filter(None.__ne__, [inner_loop(i) for i in range(2, x+1)]))

def inner_loop(i):
    for j in range(2, i):
        if i % j == 0: 
            break
    else:
        return i


print(f(num));