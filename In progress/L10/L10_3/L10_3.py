
class SomeObject:
    def __init__(self, *args, **kwargs):
         self.value = args[0]

class SomeObjectx2():
    def __init__(self, obj):       
         self.value = obj.value*2

obj = SomeObject(int(input('Enter number: ' )))
print(obj.value)
print(SomeObjectx2(obj).value)