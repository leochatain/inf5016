#!/usr/bin/python

import sys
import os
from time import time

import matplotlib.pyplot as plt
import pickle

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

if argc < 3:
  print './run start_size num_steps step_size (optional) function_family'
  exit(1)

start = int(argv[1])
num_steps = int(argv[2])
step_size = int(argv[3])

if argc > 4:
  fun_family = int(argv[4])
else:
  fun_family = 1

times = []

# Run tests
for i in xrange(num_steps):
  sx = start + i * step_size
  print sx
  # Generate graph and put it into files
  out_file = 'files/' + str(i) + 'function_' + str(fun_family)
  os.popen(get_gen(1, sx, out_file))

  t = run(out_file) 
  times.append((sx, t))


# Plot results
ax = plt.subplot(111)

plt.ylabel('Time(s)')
plt.xlabel('Size')
plt.title('Fattest-path')
plt.xticks(list(x[0] for x in times), rotation=30, size='small')
plt.grid(True)

ax.plot(list(x[0] for x in times),
        list(x[1] for x in times),
        label='graph_' + str(fun_family))

box = ax.get_position()
ax.set_position([box.x0, box.y0+box.height*0.1, box.width, box.height*0.9])

ax.legend(loc='upper center', bbox_to_anchor=(0.5, -0.1),
          fancybox=True, shadow=True,ncol=3)

plt.show()

pickle.dump(times, open('result_' + str(fun_family), 'wb'))
