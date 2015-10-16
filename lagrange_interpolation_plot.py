import numpy as np
import matplotlib.pyplot as plt

data_sets = (("lagrange_interpolation_dane", "go", "Dane"),
             ("lagrange_interpolation_fit", "b-", "Lagrange"),
             ("neville_interpolation_fit", "r-", "Neville"))

for data_set, format_string, label_string in data_sets:
    data = np.loadtxt(data_set)
    data_x = data[:,0]
    data_y = data[:,1]

    plt.plot(data_x, data_y, format_string, label=label_string)
plt.title("TOTALLY GNUPLOT")
plt.grid()
plt.legend()
plt.show()
