import numpy as np 
import matplotlib.pylab as plt

datos=np.genfromtxt("datos.dat")
x=datos[:,0]
y=datos[:,1]

plt.figure()
plt.plot(x,y, label='y(x)')
plt.xlabel("x")
plt.ylabel("y")
plt.ylim(-0.2,2)
plt.title("Euler")
plt.legend()
plt.savefig("plotS5C2.png")


datosrunge=np.genfromtxt("datosr4.dat")
xr=datos[:,0]
yr=datos[:,1]

plt.figure()
plt.plot(x,y, color='m',label='y(x)')
plt.xlabel("x")
plt.ylabel("y")
plt.ylim(-0.2,2)
plt.legend()
plt.title("Runge-Kutta")
plt.savefig("plotS5C2r4.png")