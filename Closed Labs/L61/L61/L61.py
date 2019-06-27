class Engine:
    def get_type(self):
        return type(self)     
    def isinstance(self, t):
        return isinstance(self, t)
    def issubclass(self,t):
        return issubclass(type(self), t)

# engines
class HorsePower(Engine):
    def __init__(self):
        super().__init__()
        self.horses = 4
    pass
    def Upgrade(self):
        return SteamEngine()
pass

class SteamEngine(HorsePower):
    def __init__(self):
        super().__init__()
        self.water_tank_volume = 3000 # liters
        self.water_temperature = 120 # C
    pass
    def Upgrade(self):
        return InternalCombustionHeatEngine()
pass

class InternalCombustionHeatEngine(SteamEngine):
    def __init__(self):
        super().__init__()
        self.cylinders = 4
        self.fuel = 'diesel'
    pass
    def Upgrade(self):
        return ElectricEngine()
pass


class ElectricEngine(InternalCombustionHeatEngine):
    def __init__(self):
        super().__init__()
        self.panels = 4
        self.dimentions = (2,3) 
        self.kwatt_power = 7 #kW
    pass
    def Upgrade(self):
        return RocketEngine()
pass

class RocketEngine(InternalCombustionHeatEngine):
    def __init__(self):
        super().__init__()
        self.fuelTank = 4
        self.dimentions = (2,3) 
        self.kwatt_power = 7 #kW
    def Upgrade(self):
        return IonThruster()
    pass
pass

class IonThruster(InternalCombustionHeatEngine):
    def __init__(self):
        super().__init__()
        self.gas = 'xenon'
        self.power_need = 7 # kW
        self.gas_weight = 100 # kg
        self.exhaust_velosity = 50 # km/s
    def Upgrade(self):
        return WarpEngine()
    pass
pass

class WarpEngine(IonThruster):
    def __init__(self):
        super().__init__()
        self.exhaust_velosity = 10 ** 10 # km/s
    def Upgrade(self):
        return WarpEngine()
    pass
pass

w = WarpEngine()
print(w.isinstance(WarpEngine))
print(w.issubclass(Engine))

