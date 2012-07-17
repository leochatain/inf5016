#!/usr/bin/python
#Author: leochatain@gmail.com (Leo Chatain)

import sys
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from math import log
import os

def inv_log_log(tup):
  if tup[0] <= 0.:
    return tup[1] / float(log(log(tup[0], 2), 2))
  return 0.

num_benchs = 10

sizes = []
push = []
pop = []
update = []

for i in xrange(10, 13):
  size = 2 ** i
  stream = os.popen('./bin/bench_heap -b ' + str(num_benchs) + ' -s ' + str(size))
  sizes.append(int(size))
  push.append(float(stream.next().rstrip()))
  pop.append(float(stream.next().rstrip()))
  update.append(float(stream.next().rstrip()))

plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('VEB Benchmark')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, push, 'r--', label='serial')
plt.plot(sizes, pop, 'b--', label='acc')
plt.plot(sizes, update, 'g--', label='cublas')
plt.legend(loc="upper left")

plt.savefig('heap.png')

# Plot inverse
plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('VEB Benchmark Normalized')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, map(inv_log_log, zip(sizes, push)), 'r--', label='serial')
plt.plot(sizes, map(inv_log_log, zip(sizes, pop)), 'b--', label='acc')
plt.plot(sizes, map(inv_log_log, zip(sizes, update)), 'g--', label='cublas')
plt.legend(loc="upper left")

plt.savefig('heap_inv.png')

print '# x f(x)'
for s, t in zip(sizes, push):
  print s, t
print '# x f(x)'
for s, t in zip(sizes, pop):
  print s, t
print '# x f(x)'
for s, t in zip(sizes, update):
  print s, t


