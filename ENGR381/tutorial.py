import numpy as np
import matplotlib.pyplot as plt
######  Example 1.11 ##########
# load text file
fname = 'exp01-11.csv' # comma separated values
data1 = np.loadtxt(fname, delimiter=',', skiprows=1)  #skip first row
# print (data1)
fig, ax = plt.subplots(1, 2)   # Create a figure containing a single axes
ax[0].hist(data1, ec='black')
ax[0].set_title("Equal width bins")
ax[1].hist(data1, ec='black', bins=[2, 4, 6, 8, 12, 20, 30])
ax[1].set_title("Unequal width")
ax[0].set_xlabel('Bond strength')
ax[1].set_xlabel('Bond strength')
ax[0].set_ylabel('')
plt.show()