import numpy as np
import matplotlib.pyplot as plt



datos = np.loadtxt("ejercicio32.dat")
s=np.shape(datos)
print(s)
plt.figure(figsize=(20,8))
plt.subplot(2,3,1)
plt.imshow(datos, aspect=0.1)
#para realizar las otras dos graficas me guié de la solucion del ejercicio 29 dada por el profesor.
plt.subplot(2,3,2)
numx=100
numt=1000
x = np.linspace(-1,1,numx)
delta_t = 1.0/numt
for i in range(numt):
        if i%(numt//9) == 0:
            plt.plot(x, datos[i,:],label="t={:.02f}".format(i*delta_t))
            plt.legend(loc=1)
            
plt.subplot(2,3,3)
t=np.linspace(0,1,numt)
x1=datos[:,numx//4]
plt.plot(t,x1)
plt.savefig("ejercicio32.png")


