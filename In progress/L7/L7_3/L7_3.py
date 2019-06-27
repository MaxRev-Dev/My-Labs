
from itertools import cycle
class Calculator:    
    def __init__(self):
        self.ops = {
            '+':Fraction.__add__,
            '-':Fraction.__sub__,
            '*':Fraction.__mul__,
            '/':Fraction.__div__,
            'gcd': Fraction.greatest_common_divider
            }
        self.read_input()
    def get_fractions(self, arr):
        l = []
        for i in arr:
            parts = i.split('/')
            l.append(Fraction(int(parts[0]),int(parts[1])))
        return l
    def read_input(self):
        self.operand_list = []
        self.operator_list = []

        ncor = True
        while ncor:
            expr = input("Enter expression: ")
            try:
                expr = expr.split()

                self.operator_list = expr[1::2]
                self.operand_list = self.get_fractions(expr[::2])         
       
                backprint = self.printAll() 
                it_operator = cycle(self.operator_list) # ітератор списку операторів
                it_list = cycle(self.operand_list)# ітератор списку змінних
                first = next(it_list)
                for i in self.operand_list[1:]: 
                    first = self.ops[next(it_operator)](first, i) 
                print(backprint + ' = ' + str(first))
            except:
                print('Error in recognizing expression. Please, try again')
                print('Ex. format: 4/5 + 3/5')
        pass
    def printAll(self):
        part = []
        for num,oper in zip(self.operand_list,self.operator_list):
            part.append(str(num))
            part.append(' %s  ' % oper) # формат
        part.append(str(self.operand_list[-1]))
        return "".join(part)



class Fraction:
    def __init__(self, num, den):
        self.num = num
        self.den = den
    def __add__(self, a):
        self.num = self.num * a.den + self.den * a.num
        self.den = self.den * a.den
        return self

    def __sub__(self, a):
        self.num = self.num * a.den - self.den * a.num
        self.den = self.den * a.den
        return self

    def __mul__(self, a):
        self.num = self.num * a.num
        self.den = self.den * a.den
        return self

    def __div__(self, a):
        self.num = self.num * a.den
        self.den = self.den * a.num
        return self
     
    def __str__(self):
        s = self.simplify(self.num,self.den)
        return str(s.num) + '/' + str(s.den)

    def mod(self,a,b):
        return a.__div__( a.__sub__(b))
    def greatest_common_divider(self, frac):
        a = self.decimal()
        b = frac.decimal()
        while b:
            a, b = b, a%b
        return a

        
    def decimal(self, accuracy=3):
        return round(float(self.num) / float(self.den), accuracy)

    def simplify(self, num, den):
        self.num = num
        self.den = den
        i = 2
        while i <= self.den:
            if self.num % i == 0:
                if self.den % i == 0:
                    self.num /= i
                    self.den /= i
                    i = 1
            i += 1
        return self



Calculator()
