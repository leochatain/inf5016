from math import log
import sys

name = sys.argv[1]
f = open(name)
print f.readline().rstrip() #skip first line

for line in f:
  a = tuple(line.strip().split(' '))
  x = int(a[0])
  fx = float(a[1])
  print x, fx / ((x ** 2) * log(x, 2))
