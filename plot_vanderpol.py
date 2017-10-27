import matplotlib.pyplot as plt
import numpy as np


rk4_arr = np.loadtxt('rk4_vanderpol_0.88.txt')

plt.plot(rk4_arr[:, 1], rk4_arr[:, 2])

plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.title("Van der Pol oscillator (Runge-Kutta 4th Order) mu=0.88")

plt.savefig("rk4_vanderpol_0.88.png")
