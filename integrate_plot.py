import numpy as np
import matplotlib.pyplot as plt
analytical = -2*np.pi

file_name = "integrate_results"
data = np.loadtxt(file_name)
h = data[:,0]
#data[:,1:] = (data[:,1:]-analytical)/analytical
rectangular=data[:,1]
trapezoidal=data[:,2]
simpson=data[:,3]
boole=data[:,4]
rect_correction=data[:,5]

plt.plot(h, rectangular, label="rect")
#plt.plot(h, rect_correction, label="rect correction")
plt.plot(h, trapezoidal, label="trap")
plt.plot(h, simpson, label="simp")
plt.plot(h, boole, label="bool")
plt.legend()
plt.show()
