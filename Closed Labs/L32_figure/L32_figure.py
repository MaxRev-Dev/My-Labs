import math
from itertools import cycle
class Point(object):
    def __init__(self, x, y):
        super(Point, self).__init__()
        self.x = x
        self.y = y

class Ruller(object): 
    def __init__(self):
        super(Ruller, self).__init__()

    def get_perimeter(self, points):
        """ returns the length of the perimiter of some shape defined by a list of points """
        distances = self.get_distances(points)
        
        length = 0
        for distance in distances:
            length += distance

        return length 

    def get_area(self, points):
        n = len(points) # of corners
        area = 0.0
        for i in range(n):
            j = (i + 1) % n
            area += points[i].x * points[j].y
            area -= points[j].x * points[i].y
        area = abs(area) / 2.0
        return area

    def get_distances(self, points):
        """ convert a list of points into a list of distances """
        distances = []
         
        buff=cycle(points)
        previous_point  = next(buff )

        for i in range(len(points)):
            point =  next( buff)
            distance = self.get_distance(previous_point, point)
            distances.append(distance)

            previous_point = point

        return distances

    def get_distance(self, point1, point2):
        """ use pythagorean theorm to find distance between 2 points """
        a = point1.x - point2.x
        b = point1.y - point2.y
        return math.sqrt(a**2 + b**2)



points = [Point(0,0),Point(6,0),Point(6,6),Point(0,6)] #square 6x6
rul = Ruller();
print('Perimeter of poly: %s units' % rul.get_perimeter(points))
print('Area of poly: %s square units' % rul.get_area(points))
