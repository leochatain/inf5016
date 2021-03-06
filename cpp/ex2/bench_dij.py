#!/usr/bin/python
#Author: leochatain@gmail.com (Leo Chatain)

import sys
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import os
from math import log

def generate(size):
  os.system('../files/gen ' + str(size) + ' 1 > ../files/' + str(size) + '.gr')

def inv(tup):
  x = tup[0]
  fx = tup[1]
  if fx > 0:
    return fx / (x * log(log(x, 2), 2))
  return 0.

num_benchs = 10

sizes = []
times = []

print '# x f(x)'
for i in xrange(512, 8192+512, 512):
  sys.stderr.write(str(i) + "\n")
  size = i
  sname = str(size)
  graph_file = '../files/' + str(sname) + '.gr'

  if not os.path.exists(graph_file):
    generate(size)

  stream = os.popen('./bin/bench_dij -b ' + str(num_benchs) + ' -g ' + graph_file)

  sizes.append(int(size))
  times.append(float(stream.next().rstrip()))
  print size, times[-1]

plt.figure(1)
plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('Dijkstra')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, times, 'r--', label='dijkstra')
plt.savefig('dij2.png')

plt.figure(2)
plt.subplot(111)
plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('Dijkstra inverse')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, map(inv, zip(sizes, times)), 'r--', label='dijkstra_inv')
plt.savefig('dij_inv2.png')
