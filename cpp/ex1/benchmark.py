#!/usr/bin/python
import os

num_benchs = 100

print '# x f(x)'
for i in xrange(5, 12):
  u = str(2 ** i)
  graph = 'files/' + str(u) + '.gr'
  stream = os.popen('./bin/ex1 -b ' + str(num_benchs) + ' -g ' + graph)
  print u, stream.next().rstrip()
