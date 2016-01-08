import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("ode_data")
t, Neuler, Nmodified, NRK, Nexact = (data[:,i] for i in range(5))
plt.plot(t, Neuler, "go", label="Euler")
plt.plot(t, Nmodified, "ro", label="Modified Euler")
plt.plot(t, NRK, "bo", label="Runge Kutta")
plt.plot(t, Nexact, "y-", label="Exact")
plt.grid(True)
plt.legend()
plt.yscale('log')
plt.show()
