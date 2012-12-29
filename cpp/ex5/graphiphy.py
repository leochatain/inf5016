#!/usr/bin/python

import sys
import matplotlib.pyplot as plt

argv = sys.argv
argc = len(argv)

if argc < 2:
  print 'param'
  exit(1)

file_name = argv[1]
times = open(file_name, 'rb')

sizes = range(10000)
occupancy = map(lambda x: 100*x/10000., sizes)

# parse all times
all_times = []
for t in times:
  all_times.append(t.split())
  print all_times[-1]

linked = list(float(x[0]) for x in all_times)
open_s = list(float(x[1]) for x in all_times)
cuckoo = list(float(x[2]) for x in all_times)

ax = plt.subplot(111)

plt.xlabel('Occupancy %')
plt.ylabel('Steps');
plt.title('Lookup operation')
plt.xticks(map(lambda x: 10 * x, range(11)), rotation=30, size='small')
plt.grid(True)

#ax.scatter(occupancy, linked, s=1, color='r', label='chaining')
#ax.scatter(occupancy, open_s, s=1, color='g', label='open')
ax.plot(occupancy, cuckoo, color='b', label='cuckoo')
ax.legend(loc='upper left')

plt.show()

