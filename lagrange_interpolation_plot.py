import numpy as np
import matplotlib.pyplot as plt

points = np.loadtxt("lagrange_interpolation_dane")
fit = np.loadtxt("lagrange_interpolation_fit")

print(points)
print(fit)

points_x = points[:,0]
points_y = points[:,1]

fit_x = fit[:,0]
fit_y = fit[:,1]

plt.plot(points_x, points_y, "bo")
plt.plot(fit_x, fit_y, "g-")
plt.show()
