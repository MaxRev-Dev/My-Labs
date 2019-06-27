import math

T0 = 15
n = 15
h = 0.1
a2 = 0.000397554
Tn = 50*n
a1 = 1/n
T = 4.192307692

arrayO = [T0]
k = []
a = []
b = []
c = []

for i in range(1, 5):
    arrayO.append(round((Tn-T0)*math.pow(i/10,3)/math.pow(0.5,3)+T0,5))
arrayO.append(Tn)
print(arrayO)

for i in range(0, 5):
    k.append(a2*(1+math.exp(-a1*(i/10+0.05))))

for i in range(0, 4):
    a.append(T*k[i]/math.pow(h,2))
    b.append(T*k[i+1]/math.pow(h,2))
    c.append(1+a[i]+b[i])

for i in range(1, 4):
    array = [Tn]
    L = [0]
    B = [T0]
    for j in range(1, 5):
        L.append(b[j-1]/(c[j-1]-a[j-1]*L[j-1]))
        B.append((a[j-1]*B[j-1]+arrayO[j])/(c[j-1]-a[j-1]*L[j-1]))
    for k in range(4, 0, -1):
        array.append(round(L[k]*array[4-k]+B[k],5))
    array.append(T0)
    array.reverse()
    arrayO[:] = array[:]
    print(arrayO)


