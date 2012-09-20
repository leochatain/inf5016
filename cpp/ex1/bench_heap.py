#!/usr/bin/python
import os

num_benchs = 10

push = []
pop = []
update = []

for size in xrange(2**14, 2**18, 2**14):
  stream = os.popen('./bin/bench_heap -b ' + str(num_benchs) + ' -s ' + str(size))
  push.append((size, stream.next().rstrip()))
  pop.append((size, stream.next().rstrip()))
  update.append((size, stream.next().rstrip()))

print '# x f(x)'
for t in push:
  print t[0], t[1]
print '# x f(x)'
for t in pop:
  print t[0], t[1]
print '# x f(x)'
for t in update:
  print t[0], t[1]


