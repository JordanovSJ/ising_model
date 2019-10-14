import numpy as np
import matplotlib.pyplot as plt

def grad_data(x,y,n):
	"computes the gradient of noisy data points (x,y) by fitting local linear dependece on n points"
	grad=np.zeros(len(E)-(n-1))
	 
	for i in range(0,len(E)-n):
		y_local=np.take(y,np.arange(n)+i)		
		x_local=np.take(x,np.arange(n)+i)
		grad[i]= np.polyfit(x_local,y_local, 1)[0]
	
	return grad

plt.figure(1)

plt.subplot(211)
T, M, E= np.loadtxt('data', delimiter=',', unpack=True)
plt.plot(T,M, 'co',label='T=1.5')
plt.plot(T,M, 'c' )
plt.ylabel('M ')
plt.xlabel('H / (J/mu)')
plt.grid()
plt.legend(loc=4)
plt.title("Equillibrium E and M vs H ")

plt.subplot(212)
T, M, E= np.loadtxt('data', delimiter=',', unpack=True)
plt.plot(T,E, 'go',label='T=2')
plt.plot(T,E, 'g' )
plt.ylabel('E ')
plt.xlabel('H / (J/mu)')
plt.grid()
plt.legend(loc=2)


plt.savefig("plot.pdf")

