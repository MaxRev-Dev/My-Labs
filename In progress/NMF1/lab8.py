import math

w = 15
y1 = 0.1
y2 = 0.1

Y0 = 15*math.sin(w*0/10)
Yn = []
X0 = []
Xn = 0
arrayO = [[Y0],[],[],[Y0, Xn, Xn, Xn]] 

for i in range(1, 4):
    X0.append(3*i)
    arrayO[0].append(X0[i-1])

for j in range(0, 4):
    Yn.append(12-4*j+math.cos(w*0/10))


for k in range(1, 3):
    arrayO[k].append(Y0)
    for m in range(1, 4):
        arrayO[k].append(round(15*math.sin(k*math.pi/4)*math.cos(m*math.pi/3),5))
    arrayO[k].append(Yn[k])

print("Значення на 0 часовому шарі")
for i in range(0, 4):
    print(arrayO[i])

for i in range(1, 4):
    array = [[],[],[],[]]
    Yn = []
    print("\nЗначення на {0} часовому шарі".format(i))
    Y0 = round(15*math.sin(w*i/10),5)
    for j in range(0, 4):
        Yn.append(round(12-4*j+math.cos(w*i/10),5))
    array[0].append(Y0)
    array[3].append(Y0)
    for i in range(1, 4):
        array[0].append(X0[i-1])
    array[0].append(Yn[0])
    for k in range(1, 3):
        array[k].append(Y0)
        for m in range(1, 4):
            array[k].append(round(arrayO[k][m]+y1*(arrayO[k][m+1]-2*arrayO[k][m]+arrayO[k][m-1])+y2*(arrayO[k+1][m]-2*arrayO[k][m]+arrayO[k-1][m]),5))
        array[3].append(Xn)
        array[k].append(Yn[k])
    array[3].append(Xn)
    array[3].append(Yn[3])
    arrayO[:][:] = array[:][:]
    for i in range(0, 4):
        print(array[i])