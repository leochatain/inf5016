#!/usr/bin/python
import os

def generate(size):
  os.system('bin/gen ' + str(size) + ' 1 > ../files/' + str(size) + '.gr')

num_benchs = 10

print '# x f(x)'
for i in xrange(512, 8192+512, 512):
  size = i
  sname = str(size)
  graph_file = '../files/' + str(sname) + '.gr'

  if not os.path.exists(graph_file):
    generate(size)

  stream = os.popen('./bin/bench_dij -b ' + str(num_benchs) + ' -g ' + graph_file)
  print size, stream.next().rstrip()
