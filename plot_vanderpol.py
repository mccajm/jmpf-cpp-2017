import matplotlib.pyplot as plt
import numpy as np


rk4_arr = np.loadtxt('rk4_vanderpol.txt')

plt.plot(rk4_arr[:, 1], rk4_arr[:, 2])

plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("Van der Pol oscillator (Runge-Kutta 4th Order) mu=7")

plt.show()
plt.savefig("rk4_vanderpol_7.png")
