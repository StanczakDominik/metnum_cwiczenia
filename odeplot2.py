import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("ode_data_2")
t = data[:,0]
for i in range(1, data.shape[1]):
    plt.plot(t, data[:,i], label=str(i))
plt.grid(True)
plt.legend()
plt.show()
