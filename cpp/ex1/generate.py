#!/usr/bin/python
import os

for i in xrange(5, 12):
  i = str(2 ** i)
  print 'Generating graph ', i, '...'
  os.system('bin/gen ' + i + ' 1 > files/' + i + '.gr') 
