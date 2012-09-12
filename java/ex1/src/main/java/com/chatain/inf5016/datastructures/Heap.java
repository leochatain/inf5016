package com.chatain.inf5016.datastructures;

import java.util.Collection;

/**
 * Defines a Heap.
 *
 * Author: leochatain@gmail.com (Leo Chatain)
 */
public interface Heap<T extends Comparable<T>>{
  void add(T e);
  void addAll(Iterable<? extends T> e);

  boolean contains(T e);
  boolean isEmpty();

  T pop();
  T top();

  int size();
}
