#!/usr/bin/python

import sys
import os
from time import time

import matplotlib.pyplot as plt

def get_gen(fun_family, sx, out):
  return './bin/gengraph ' + str(fun_family) + ' ' + str(sx) \
          + ' ' + str(sx) + ' ' + str(100) + ' ' + str(out)

def run(inp):
  init = time()
  my_result = os.popen('./bin/ex3 < ' + str(inp)).next().rstrip()
  end = time()

  gold_result = os.popen('./bin/validate < ' + str(inp)).next().rstrip()

  if (int(my_result) != int(gold_result)):
    print "Results don't match"
    exit(1)

  return end-init

argv = sys.argv
argc = len(argv)

if argc < 4:
  print 'parameters'
  exit(1)

fun_family = int(argv[1])
start = int(argv[2])
num_steps = int(argv[3])
step_size = int(argv[4])

sizes = []
times1 = []
times4 = []

# Run tests
for i in xrange(num_steps):
  sx = start + i * step_size
  print sx
  # Generate graph and put it into files
  out1 = 'files/' + str(i) + '1'
  out4 = 'files/' + str(i) + '4'
  os.popen(get_gen(fun_family, sx, out1))
  os.popen(get_gen(fun_family, sx, out4))

  time1 = run(out1) 
  time4 = run(out4)

  sizes.append(sx)
  times1.append(time1)
  times4.append(time4)


# Plot results
plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('Fattest-path')
plt.xticks(sizes, rotation=30, size='small')
plt.grid(True)

plt.plot(sizes, time1)
plt.plot(sizes, time4)

plt.show()

print times
