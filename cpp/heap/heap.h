#ifndef HEAP_H
#define HEAP_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

template <typename Key, typename Value>
struct HeapNode {
    Key key;
    Value value;
};

template <typename Node>
class Heap
{
private:
    Node *array;
    int heapSize;
public:
    Heap(int initialArraySize);
    Node pop();
    void insert(Node node);
    void dump();
};

template <typename Node>
Heap<Node>::Heap(int initialArraySize)
{
    array = (Node*) malloc(sizeof(Node) * initialArraySize + 1);
    heapSize = 0;
}

template <typename Node>
Node Heap<Node>::pop()
{
    // If the heap is empty, do not return anything.
    if (heapSize == 0) {
        return NULL;
    }

    // Copy the last value in the heap to the root.
    Node root = array[1];
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
    int currentKey, leftChildKey, rightChildKey, minChildKey;
    Node tmp;

    current = 1;
    leftChild = 2;
    rightChild = 3;

    currentKey = array[current]->getKey();
    leftChildKey = array[leftChild]->getKey();

    if (rightChild > heapSize) {
        minChildKey = leftChildKey;
        minChild = leftChild;
    } else {
        rightChildKey = array[rightChild]->getKey();

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

        currentKey = array[current]->getKey();

        if (leftChild > heapSize) {
            break;
        }

        leftChildKey = array[leftChildKey]->getKey();

        if (rightChild > heapSize) {
            minChildKey = leftChildKey;
            minChild = leftChild;
            break;
        }

        rightChildKey = array[rightChildKey]->getKey();

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

template <typename Node>
void Heap<Node>::insert(Node node)
{
    array[heapSize+1] = node;

    int current = heapSize+1;
    int parent = floor(current/2);

    heapSize++;

    if (parent < 1) {
        return;
    }

    Node tmp;

    while (array[current]->getKey() < array[parent]->getKey()) {
        tmp = array[current];
        array[current] = array[parent];
        array[parent] = tmp;

        current = parent;
        parent = floor(current/2);
    }
}

template <typename Node>
void Heap<Node>::dump()
{
    printf("heap size: %d\n", heapSize);

    for (int i = 1; i < (heapSize+1); i++) {
        printf("%d => %d\n", i, array[i]->getKey());
    }

    printf("\n");
}

#endif
