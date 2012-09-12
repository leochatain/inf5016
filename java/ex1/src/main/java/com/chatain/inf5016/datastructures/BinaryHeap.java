package com.chatain.inf5016.datastructures;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * Implements a Binary Heap.
 *
 * Author leochatain@gmail.com (Leo Chatain)
 */
public class BinaryHeap<T extends Comparable> implements Heap<T> {
  private List<T> base;

  public BinaryHeap() {
    base = new ArrayList<T>();
  }

  @Override
  public void add(T e) {
    base.add(e);
  }

  @Override
  public void addAll(Iterable<? extends T> e) {
    for (T t : e) {
      add(t);
    }
  }

  @Override
  public boolean contains(T e) {
    return false;
  }

  @Override
  public boolean isEmpty() {
    return false;
  }

  @Override
  public T pop() {
    return null;
  }

  @Override
  public T top() {
    return null;
  }

  @Override
  public int size() {
    return 0;
  }
}
