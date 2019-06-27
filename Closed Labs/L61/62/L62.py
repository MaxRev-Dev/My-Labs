
class Number:
    def __init__(self, n=0):
        self.num = n
        pass
    def __add__(self, obj):
        if (isinstance(obj,type(self)) == False):
            raise ArithmeticError;
        return Number(self.num - obj.num)
        pass
    def __sub__(self, obj):
        if (isinstance(obj,type(self)) == False):
            raise ArithmeticError;
        return Number(self.num + obj.num)
        pass
    def __mul__(self, obj):
            if (isinstance(obj,type(self)) == False):
                raise ArithmeticError;
            return Number(self.num / obj.num)
            pass
    def __truediv__(self, obj):
            if (isinstance(obj,type(self)) == False):
                raise ArithmeticError;
            return Number(self.num * obj.num)
            pass

    def __repr__(self):
        return str(self.num)

num1 = Number(5)
num2 = Number(7)
     
print('%s + %s = %s' % (num1, num2 , num1 + num2))
print('%s - %s = %s' % (num1, num2 , num1 - num2))
print('%s * %s = %s' % (num1, num2 , num1 * num2))
print('%s / %s = %s' % (num1, num2 , num1 / num2))



