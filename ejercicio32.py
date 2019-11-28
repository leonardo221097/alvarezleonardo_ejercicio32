import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


datos = np.loadtxt("ejercicio32.dat")


fig = plt.figure(figsize=(20,5))
x = np.linspace(0, 1,np.shape(datos)[1])

t = np.linspace(0,6,np.shape(datos)[0])

pos, tiempo= np.meshgrid(x,t)
ax = fig.add_subplot(121,projection="3d")
grafica = ax.plot_surface(pos,tiempo,datos)

plt.subplot(1,2,2)
plt.plot(x,datos[0,:],label='t_ini = 0')
plt.plot(x,datos[-1,:],label='t_final = 6')
plt.legend()

plt.savefig("ejercicio32.png")
