#!/usr/bin/python
#Author: leochatain@gmail.com (Leo Chatain)

import sys
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import os

num_benchs = 10

sizes = []
push = []
pop = []
update = []

for i in xrange(10, 20):
  size = 2 ** i
  stream = os.popen('./bin/bench_heap -b ' + str(num_benchs) + ' -s ' + str(size))
  sizes.append(size)
  push.append(stream.next().rstrip())
  pop.append(stream.next().rstrip())
  update.append(stream.next().rstrip())

plt.subplot(111)

plt.ylabel('Size');
plt.title('Time(s)')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, push, 'r--', label='serial')
plt.plot(sizes, pop, 'b--', label='acc')
plt.plot(sizes, update, 'g--', label='cublas')

plt.savefig('heap.png')

print '# x f(x)'
for s, t in zip(sizes, push):
  print s, t
print '# x f(x)'
for s, t in zip(sizes, pop):
  print s, t
print '# x f(x)'
for s, t in zip(sizes, update):
  print s, t


