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
occupancy = map(lambda x: x/10000., sizes)

for o in occupancy:
  print o
