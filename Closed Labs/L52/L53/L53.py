class Frame(object):
    def __init__(self):
        super().__init__()
        print("Created a basic frame")
        pass
    def dimentions(self):
        print("This is a frame dimentions")
        pass
class Wheel(object):
    def __init__(self):
        super().__init__()
        print("Created wheel with frame")
        pass
    def radius(self):
        print("This is a wheel radius")        
        pass
class Carriage(Wheel, Frame):
    def __init__(self):
        super().__init__()
        print("Carriage built from wheel and frame")
        pass
    def dimentions(self):
        print("This is a carriage 3D dimentions")
    pass

class Cab:
    def __init__(self):
        super().__init__()
        print("Created cab")
        pass
    def dimentions(self):
        print("This is a cab dimentions")
    pass

class Car(Cab, Carriage):
    def __init__(self):
        super().__init__()
        print("Car built from carriage and cab")
        pass 
    def dimentions(self):
        print("This is a civil car dimentions")

class Wing(Frame):
    def __init__(self):
        super().__init__()
        print("Wing built")
        pass
    def wings_dimentions(self):
        print("This is a wing dimentions")
    pass

class Plane(Wing,Car):
    def __init__(self):
        super().__init__()
        print("Plane built!")
        pass   

obj = Plane() 
obj.radius()
obj.wings_dimentions()
obj.radius()


print(Plane.mro())
