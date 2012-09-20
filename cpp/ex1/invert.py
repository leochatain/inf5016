from math import log

f = open('bench.txt')
print f.readline() #skip first line

for line in f:
  a = tuple(line.strip().split(' '))
  x = int(a[0])
  fx = float(a[1])
  print x, fx / ((x ** 2) * log(x, 2))
