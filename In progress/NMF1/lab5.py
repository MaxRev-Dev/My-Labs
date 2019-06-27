import math

T0 = 10
n = 15
h = 0.2
Tn = round(T0*math.pow(math.sin(n), 2),5)

arrayO = [T0]
R = []
M = []
Rp = []
Rm = []
a = []
b = []
c = []

for i in range(2, 10, 2):
    arrayO.append(round(T0*math.pow(math.sin(n*i/10),2),5))
arrayO.append(Tn)
print(arrayO)

for i in range(0, 12, 2):
    R.append(n*math.cos(math.pi*i/10))
print()
print(R)
print()
for i in range(0, 6):
    M.append(1/(1+0.5*h*math.fabs(R[i])))
    Rp.append(0.5*(R[i]+math.fabs(R[i])))
    Rm.append(0.5*(R[i]-math.fabs(R[i])))
    a.append(M[i]/math.pow(h,2)-Rp[i]/h)
    b.append(M[i]/math.pow(h,2)+Rm[i]/h)
    c.append(1+2*M[i]/math.pow(h,2)+R[i]/h)

for i in range(1, 4):
    array = [Tn]
    L = [0]
    B = [10]
    for j in range(1, 5):
        L.append(b[j]/(c[j]-a[j]*L[j-1]))
        B.append((a[j]*B[j-1]+arrayO[j])/(c[j]-a[j]*L[j-1]))
    for k in range(4, 0, -1):
        array.append(round(L[k]*array[4-k]+B[k],5))
    array.append(T0)
    array.reverse()
    arrayO[:] = array[:]
    print(arrayO)

