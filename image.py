import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import time

##creates and image of 100x100 latice from text file

while 1>0:
	string_lattice = open('print', 'r').read()
	if len(string_lattice)==10100:
		arr=np.arange(10000)
		count=0
		for i in range(len(string_lattice)):
			if string_lattice[i] != '\n':
				arr[count]=int(string_lattice[i])
				count+=1

		arr.shape=(100,100)

		plt.figure(1)

		plt.imshow(arr)
		plt.title('T=2.3')
		plt.savefig("image.pdf")

	time.sleep(0.1)








#~ plt.figure(2)





#~ T, S= np.loadtxt('size_domains', delimiter=',', unpack=True)
#~ plt.plot(T,S, 'co')
#~ plt.plot(T,S, 'c' )
#~ plt.ylabel('Size / number of lattice sites ')
#~ plt.xlabel('T / (J/k)')
#~ plt.grid()
plt.legend(loc=4)
#~ plt.title("Typical maximum size of domains for 100x100 lattice vs T ")

	
#~ plt.savefig("plotsize.pdf")

