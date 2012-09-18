#!/usr/bin/python
import os

for i in xrange(5, 12):
  u = str(2 ** i)
  print 'Generating graph ', u, '...'
  os.system('bin/ex1 ' + u + ' 1 > files/' + u + '.gr') 
