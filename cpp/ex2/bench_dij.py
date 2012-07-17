#!/usr/bin/python
#Author: leochatain@gmail.com (Leo Chatain)

import sys
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import os

def generate(size):
  print 'generating for', size
  os.system('../files/gen ' + str(size) + ' 1 > ../files/' + str(size) + '.gr')

num_benchs = 10

sizes = []
times = []

print '# x f(x)'
for i in xrange(5, 20):
  size = 2 ** i
  sname = str(size)
  graph_file = '../files/' + str(sname) + '.gr'

  if not os.path.exists(graph_file):
    generate(size)

  stream = os.popen('./bin/bench_dij -b ' + str(num_benchs) + ' -g ' + graph_file)

  sizes.append(size)
  times.append(stream.next().rstrip())
  print size, times[len(times)-1]

plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('Dijkstra')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, times, 'r--', label='serial')

plt.savefig('dij.png')
