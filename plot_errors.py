import matplotlib.pyplot as plt
import numpy as np


rk4_arr = np.loadtxt('errors_rk4.txt')            
euler_arr = np.loadtxt('errors_euler.txt')            
hi_arr = np.loadtxt('errors_hi.txt')

plt.plot(np.log(rk4_arr[:, 0]), np.log(rk4_arr[:, 1]), label="Runga-Kutta 4th order")
plt.plot(np.log(hi_arr[:, 0]), np.log(hi_arr[:, 1]), label="Runge-Kutta 2nd order")
plt.plot(np.log(euler_arr[:, 0]), np.log(euler_arr[:, 1]), label="Forward Euler")

plt.xlabel("log time-step")
plt.ylabel("log error")
plt.legend()
plt.title("Comparison of L2 errors for different solvers")

plt.savefig("errors.png")
