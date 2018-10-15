#ifndef HEAP_H
#define HEAP_H

#include <iostream>

template <typename T> class Heap {
private:
  T *container;
  int containerSize;

public:
  Heap() : container(nullptr), containerSize(0) {}
  Heap(T *container_, int containerSize_)
      : container(container_), containerSize(containerSize_) {}
  T *HeapSort() {
    int n = this->containerSize - 1;
    while (n--) {
      this->heapifyMAX(n + 1);
      swap(0, n + 1);
    }
    return this->container;
  }
  void heapifyMAX(int lastpos) {
    int startpos = ((lastpos) / 2) + 1;
    while (startpos--) {
      this->doHeapMAX(startpos, lastpos);
    }
  }
  void doHeapMAX(int pos, int lastpos) {
    if ((pos * 2 + 1) <= lastpos) {
      if (this->container[pos * 2 + 1] > this->container[pos]) {
        swap(pos * 2 + 1, pos);
      }
    }
    if ((pos * 2 + 2) <= lastpos) {
      if (this->container[pos * 2 + 2] > this->container[pos]) {
        swap(pos * 2 + 2, pos);
      }
    }
  }
  void swap(int pos1, int pos2) {
    T temp = this->container[pos1];
    this->container[pos1] = this->container[pos2];
    this->container[pos2] = temp;
  }
  void printArray() {
    for (int i = 0; i < this->containerSize; i++) {
      std::cout << this->container[i] << " ";
    }
    std::cout << std::endl;
  }
};

#endif
