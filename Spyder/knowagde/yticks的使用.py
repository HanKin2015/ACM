import matplotlib.pyplot as plt
year = [1950, 1978, 1990, 2010]
pop = [2.519, 3.692, 5.263,6.972]
population = [1.0, 1.262, 1.650] + pop
year = [1800,1850,1900] + year

plt.fill_between(year, population, 0, color='green')

plt.xlabel('Year')
plt.ylabel('Population')
plt.title('World Population Projections')
plt.yticks([0, 1, 2, 3, 4, 5],
            ['0', '2B', '4B', '6B', '8B', '10B'])
plt.show()