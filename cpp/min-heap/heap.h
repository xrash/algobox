#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

template <typename Key, typename Value>
class HeapNode {
public:
    Key key;
    Value value;
    HeapNode(Key key, Value value);
};

template <typename Key, typename Value>
    HeapNode<Key,Value>::HeapNode(Key __key, Value __value)
{
    key = __key;
    value = __value;
}

template <typename Key, typename Value>
class Heap
{
private:
    HeapNode<Key,Value> **array;
    int heapSize;
    int arraySize;
    void growInternalArray();
public:
    Heap(int initialArraySize);
    HeapNode<Key,Value>* pop();
    void insert(Key key, Value value);
    void dump();
};

template <typename Key, typename Value>
    Heap<Key,Value>::Heap(int initialArraySize)
{
    array = (HeapNode<Key,Value>**) malloc(sizeof(HeapNode<Key,Value>*) * initialArraySize + 1);
    heapSize = 0;
    arraySize = initialArraySize;
}

template <typename Key, typename Value>
    HeapNode<Key,Value>* Heap<Key,Value>::pop()
{
    // If the heap is empty, do not return anything.
    if (heapSize == 0) {
        return NULL;
    }

    // Copy the last value in the heap to the root.
    HeapNode<Key,Value>* root = array[1];
    array[1] = array[heapSize];
    array[heapSize] = NULL;

    // Decrease the heap size by one.
    heapSize--;

    // If the heap is empty or has only one element, stop now.
    if (heapSize <= 1) {
        return root;
    }

    // Shift down the root node until it satisfies the heap property.
    unsigned int current, leftChild, rightChild, minChild;
    Key currentKey, leftChildKey, rightChildKey, minChildKey;
    HeapNode<Key,Value>* tmp;

    current = 1;
    leftChild = 2;
    rightChild = 3;

    currentKey = array[current]->key;
    leftChildKey = array[leftChild]->key;

    if (rightChild > heapSize) {
        minChildKey = leftChildKey;
        minChild = leftChild;
    } else {
        rightChildKey = array[rightChild]->key;

        if (rightChildKey < leftChildKey) {
            minChildKey = rightChildKey;
            minChild = rightChild;
        } else {
            minChildKey = leftChildKey;
            minChild = leftChild;
        }
    }

    while (minChildKey < currentKey) {
        tmp = array[current];
        array[current] = array[minChild];
        array[minChild] = tmp;

        current = minChild;
        leftChild = 2 * current;
        rightChild = leftChild + 1;

        currentKey = array[current]->key;

        if (leftChild > heapSize) {
            break;
        }

        leftChildKey = array[leftChild]->key;

        if (rightChild > heapSize) {
            minChildKey = leftChildKey;
            minChild = leftChild;
            break;
        }

        rightChildKey = array[rightChild]->key;

        if (rightChildKey < leftChildKey) {
            minChildKey = rightChildKey;
            minChild = rightChild;
        } else {
            minChildKey = leftChildKey;
            minChild = leftChild;
        }
    }

    return root;
}

template <typename Key, typename Value>
    void Heap<Key,Value>::insert(Key key, Value value)
{
    // Add a new element to the end of the array.
    HeapNode<Key,Value>* node = new HeapNode<Key,Value>(key, value);
    array[heapSize+1] = node;

    int current = heapSize+1;
    int parent = floor(current/2);

    // Advance the heap size counter.
    heapSize++;

    // Grow the internal array if needed.
    if ((heapSize+2) >= arraySize) {
        growInternalArray();
    }

    // Shift the new element up until the heap property is satisfied.
    if (parent < 1) {
        return;
    }

    HeapNode<Key,Value>* tmp;

    while (array[current]->key < array[parent]->key) {
        tmp = array[current];
        array[current] = array[parent];
        array[parent] = tmp;

        current = parent;
        parent = floor(current/2);
    }
}

template <typename Key, typename Value>
    void Heap<Key,Value>::dump()
{
    printf("heap size: %d\n", heapSize);

    for (int i = 1; i < (heapSize+1); i++) {
        printf("%d => %d\n", i, array[i]->key);
    }

    printf("\n");
}

template <typename Key, typename Value>
    void Heap<Key,Value>::growInternalArray()
{
    int newArraySize = arraySize * 2;
    HeapNode<Key,Value> **newArray = (HeapNode<Key,Value>**) malloc(sizeof(HeapNode<Key,Value>*) * newArraySize + 1);

    for (int i = 0; i < arraySize; i++) {
        newArray[i] = array[i];
    }

    free(array);
    array = newArray;
    arraySize = newArraySize;
}

#endif
