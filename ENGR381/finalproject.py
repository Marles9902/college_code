'''
EE 381 - Final Project
Due Date: 12/07/2022 at 11:59 PM
Marwin Gonzales 027340883
'''

import numpy as np
import matplotlib.pyplot as plt

# reading and importing data from the file
fileData = np.loadtxt('Sales_01_20.csv', dtype = np.float64, delimiter = ",", skiprows = 1, converters = float)
print("Data in the file:\n", fileData, "\n")
listYear = np.loadtxt('Sales_01_20.csv', dtype = int, delimiter = ",", skiprows = 1, converters = float, usecols = (0))
print("Listed Year:\n", listYear, "\n")
saleAmount = np.loadtxt('Sales_01_20.csv', dtype = int, delimiter = ",", skiprows = 1, converters = float, usecols = (1))
print("Sale Amount:\n", saleAmount, "\n")

# transpose data to separate the list years and sale amounts into a matrix
transposedData = fileData.transpose()
print("Transposed data:\n", transposedData, "\n")

# sort the transposed data from least to greatest in value
sortedData = transposedData[:, np.argsort(transposedData[0])]
print("Sorted transposed data:\n", sortedData, '\n')

# finding the frequency of each year to isolate the sale amounts in each year 
print('Frequency of listed years:')
isolatedYear, yearFrequency = np.unique(listYear, return_counts = True)           #
allYears = zip(isolatedYear, yearFrequency)
for year in allYears:
    print("The year", year[0], 'is listed', year[1], 'times')

# using the frequencies found, separate the sorted data into each year
year2001 = sortedData[0:2, 0:59584]
year2002 = sortedData[0:2, 59584:119266]
year2003 = sortedData[0:2, 119266:183505]
year2004 = sortedData[0:2, 183505:267561]
year2005 = sortedData[0:2, 267561:329163]
year2006 = sortedData[0:2, 329163:377948]
year2007 = sortedData[0:2, 377948:413565]
year2008 = sortedData[0:2, 413565:446300]
year2009 = sortedData[0:2, 446300:488808]
year2010 = sortedData[0:2, 488808:522299]
year2011 = sortedData[0:2, 522299:553364]
year2012 = sortedData[0:2, 553364:589337]
year2013 = sortedData[0:2, 589337:629280]
year2014 = sortedData[0:2, 629280:678843]
year2015 = sortedData[0:2, 678843:725494]
year2016 = sortedData[0:2, 725494:775267]
year2017 = sortedData[0:2, 775267:820958]
year2018 = sortedData[0:2, 820958:871667]
year2019 = sortedData[0:2, 871667:930621]
year2020 = sortedData[0:2, 930621:997212]

# get the sale price ranging from $200,000 to $300,000 inclusive from each year 
inclusive2001 = np.nonzero(np.logical_and(year2001[1] >= 200000, year2001[1] <= 300000))
inclusive2002 = np.nonzero(np.logical_and(year2002[1] >= 200000, year2002[1] <= 300000))
inclusive2003 = np.nonzero(np.logical_and(year2003[1] >= 200000, year2003[1] <= 300000))
inclusive2004 = np.nonzero(np.logical_and(year2004[1] >= 200000, year2004[1] <= 300000))
inclusive2005 = np.nonzero(np.logical_and(year2005[1] >= 200000, year2005[1] <= 300000))
inclusive2006 = np.nonzero(np.logical_and(year2006[1] >= 200000, year2006[1] <= 300000))
inclusive2007 = np.nonzero(np.logical_and(year2007[1] >= 200000, year2007[1] <= 300000))
inclusive2008 = np.nonzero(np.logical_and(year2008[1] >= 200000, year2008[1] <= 300000))
inclusive2009 = np.nonzero(np.logical_and(year2009[1] >= 200000, year2009[1] <= 300000))
inclusive2010 = np.nonzero(np.logical_and(year2010[1] >= 200000, year2010[1] <= 300000))
inclusive2011 = np.nonzero(np.logical_and(year2011[1] >= 200000, year2011[1] <= 300000))
inclusive2012 = np.nonzero(np.logical_and(year2012[1] >= 200000, year2012[1] <= 300000))
inclusive2013 = np.nonzero(np.logical_and(year2013[1] >= 200000, year2013[1] <= 300000))
inclusive2014 = np.nonzero(np.logical_and(year2014[1] >= 200000, year2014[1] <= 300000))
inclusive2015 = np.nonzero(np.logical_and(year2015[1] >= 200000, year2015[1] <= 300000))
inclusive2016 = np.nonzero(np.logical_and(year2016[1] >= 200000, year2016[1] <= 300000))
inclusive2017 = np.nonzero(np.logical_and(year2017[1] >= 200000, year2017[1] <= 300000))
inclusive2018 = np.nonzero(np.logical_and(year2018[1] >= 200000, year2018[1] <= 300000))
inclusive2019 = np.nonzero(np.logical_and(year2019[1] >= 200000, year2019[1] <= 300000))
inclusive2020 = np.nonzero(np.logical_and(year2020[1] >= 200000, year2020[1] <= 300000))

# calculate and print the mean prices for the years listed for the project report
print("\nMean Price for table:")
print('2001:', np.mean(year2001[1]))
print('2005:', np.mean(year2005[1]))
print('2010:', np.mean(year2010[1]))
print('2015:', np.mean(year2015[1]))
print('2020:', np.mean(year2020[1]))

# calculate and print the standard deviations for the years listed for the project report
print("\nSTD for table:")
print('2001:', np.std(year2001[1]))
print('2005:', np.std(year2005[1]))
print('2010:', np.std(year2010[1]))
print('2015:', np.std(year2015[1]))
print('2020:', np.std(year2020[1]))

# calculate and print the probabilities for the years listed for the project report
print('\nProbability for table:')
print('2001:', len(np.array(inclusive2001[0])) / yearFrequency[0])
print('2005:', len(np.array(inclusive2005[0])) / yearFrequency[4])
print('2010:', len(np.array(inclusive2010[0])) / yearFrequency[9])
print('2015:', len(np.array(inclusive2015[0])) / yearFrequency[14])
print('2020:', len(np.array(inclusive2020[0])) / yearFrequency[19])

# make a bar graph for yearly mean prices
plt.figure('Mean', figsize = (12, 6))
plt.title('Yearly Mean Prices')
plt.xticks(np.arange(min(np.unique(listYear)), max(np.unique(listYear)) + 1, 1))
plt.yticks(np.arange(0, 600000, step = 50000))
plt.xlabel('year')
plt.ylabel('mean')
plt.bar((np.unique(listYear)), [np.mean(year2001[1]), np.mean(year2002[1]), np.mean(year2003[1]), np.mean(year2004[1]), np.mean(year2005[1]), 
                                np.mean(year2006[1]), np.mean(year2007[1]), np.mean(year2008[1]), np.mean(year2009[1]), np.mean(year2010[1]), 
                                np.mean(year2011[1]), np.mean(year2012[1]), np.mean(year2013[1]), np.mean(year2014[1]), np.mean(year2015[1]), 
                                np.mean(year2016[1]), np.mean(year2017[1]), np.mean(year2018[1]), np.mean(year2019[1]), np.mean(year2020[1])])

# make a bar graph for yearly standard deviations
plt.figure('Standard Deviation', figsize = (12, 6))
plt.title('Yearly Standard Deviations')
plt.xticks(np.arange(min(np.unique(listYear)), max(np.unique(listYear)) + 1, 1))
plt.xlabel('year')
plt.yticks(np.arange(0, 6000000, step = 500000))
plt.ticklabel_format(axis = 'y', style = 'plain')
plt.ylabel('STD')
plt.bar((np.unique(listYear)), [np.std(year2001[1]), np.std(year2002[1]), np.std(year2003[1]), np.std(year2004[1]), np.std(year2005[1]), 
                                np.std(year2006[1]), np.std(year2007[1]), np.std(year2008[1]), np.std(year2009[1]), np.std(year2010[1]), 
                                np.std(year2011[1]), np.std(year2012[1]), np.std(year2013[1]), np.std(year2014[1]), np.std(year2015[1]), 
                                np.std(year2016[1]), np.std(year2017[1]), np.std(year2018[1]), np.std(year2019[1]), np.std(year2020[1])])

# make a bar graph for yearly probability of price ranging from $200,000 to $300,000 inclusive
plt.figure('Probability', figsize = (12, 6))
plt.title('Yearly Probability of Price Ranging from 200,000 to 300,000 Inclusive')
plt.xticks(np.arange(min(np.unique(listYear)), max(np.unique(listYear)) + 1, 1))
plt.xlabel('year')
plt.yticks(np.arange(0, 0.32, step = 0.02))
plt.ticklabel_format(axis = 'y', style = 'plain')
plt.ylabel('prb')
plt.bar((np.unique(listYear)), [len(np.array(inclusive2001[0])) / yearFrequency[0], len(np.array(inclusive2002[0])) / yearFrequency[1], 
                                len(np.array(inclusive2003[0])) / yearFrequency[2], len(np.array(inclusive2004[0])) / yearFrequency[3], 
                                len(np.array(inclusive2005[0])) / yearFrequency[4], len(np.array(inclusive2006[0])) / yearFrequency[5], 
                                len(np.array(inclusive2007[0])) / yearFrequency[6], len(np.array(inclusive2008[0])) / yearFrequency[7], 
                                len(np.array(inclusive2009[0])) / yearFrequency[8], len(np.array(inclusive2010[0])) / yearFrequency[9], 
                                len(np.array(inclusive2011[0])) / yearFrequency[10], len(np.array(inclusive2012[0])) / yearFrequency[11], 
                                len(np.array(inclusive2013[0])) / yearFrequency[12], len(np.array(inclusive2014[0])) / yearFrequency[13], 
                                len(np.array(inclusive2015[0])) / yearFrequency[14], len(np.array(inclusive2016[0])) / yearFrequency[15], 
                                len(np.array(inclusive2017[0])) / yearFrequency[16], len(np.array(inclusive2018[0])) / yearFrequency[17], 
                                len(np.array(inclusive2019[0])) / yearFrequency[18], len(np.array(inclusive2020[0])) / yearFrequency[19]])

# display all bar graphs
plt.show()