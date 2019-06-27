import itertools
from collections import defaultdict, Counter
 
list = [1,2,3,4,5,6,7,8,9]

def finder(num):
    strlist = "".join([str(i) for i in list])
    result = [] 
    for v in itertools.product(["+", "-", ""], repeat=9):
        if v[0] != "+":
            for vi in v:
                partial_expr = []
                for parts in zip(v, strlist):
                   partial_expr.append("".join(parts))
                solution = "".join(partial_expr) 
            if (num == eval(solution)):
               #using native python evaluation
                result.append(solution)
    return result



num = int(input("Enter number 0-100: "))
print("Finding solutions for  %d \nPlease wait..." % num)
for solution in finder(num):
    print(solution)

  