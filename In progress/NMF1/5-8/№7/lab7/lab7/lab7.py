import math

h = 0.1
T = 0.05

Y0 = []
Yn = []
Xn = []

for i in range(0, 11):
    Y0.append(round(0.5*T*i,3))
    Yn.append(round(T*i-1,3))
    Xn.append(math.pow(h*i,2)*(h*i+1))

X0 = [Y0[0]]
for i in range(1, 10):
    X0.append(round(h*i*math.cos(h*i*math.pi),5))
X0.append(Yn[0])
print(X0, sep='\t')

for i in range(1, 11):
    array = [Y0[i]]
    for j in range(1,10):
        array.append(round(X0[j]+T*Xn[j]+T*T*(X0[j+1]-2*X0[j]+X0[j-1])/(2*h*h),5))
    array.append(Yn[i])
    X0[:] = array[:]
    print(array, sep='\t')