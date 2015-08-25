#ifndef BSEARCH_H
#define BSEARCH_H

#include "node.h"

template <typename Node>
Node BinarySearch(Node *array, int arraySize, int key);

template <typename Node>
Node InternalBinarySearch(Node *array, int from, int to, int key)
{
    if (from >= to) {
        printf("from index (%d) >= to index (%d)\n", from, to);
        if (key == array[from]->getKey()) {
            return array[from];
        } else {
            return NULL;
        }
    }

    int mid = from + ((to-from)/2);

    printf("from index %d to index %d (mid index %d) [mid key %d]\n", from, to, mid, array[mid]->getKey());

    if (key < array[mid]->getKey()) {
        return InternalBinarySearch<Node>(array, from, mid-1, key);
    } else if (key > array[mid]->getKey()) {
        return InternalBinarySearch<Node>(array, mid+1, to, key);
    } else {
        return array[mid];
    }

    return NULL;
}

template <typename Node>
Node BinarySearch(Node *array, int arraySize, int key)
{
    return InternalBinarySearch(array, 0, arraySize-1, key);
}

#endif
