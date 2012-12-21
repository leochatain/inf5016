#!/usr/bin/python
import sys
import os

import matplotlib
import matplotlib.pyplot as plt

fex1 = open('dij_ex1')
fex2 = open('bench_dij_result2')

# Skip first line from both
fex1.readline()
fex2.readline()

sizes = []
ex1 = []
ex2 = []

for line in fex1:
  a = tuple(line.strip().split(' '))
  sizes.append(int(a[0]))
  ex1.append(float(a[1]))

for line in fex2:
  ex2.append(line.strip().split(' ')[1])

plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('Binary vs VEB')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, ex1, 'r--', label='Binary')
plt.plot(sizes, ex2, 'b--', label='VEB')

plt.savefig('ex1_ex2.png')


