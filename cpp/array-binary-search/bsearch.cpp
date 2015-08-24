#include "bsearch.h"
#include "node.h"
#include <stdio.h>

Node* InternalBinarySearch(Node **array, int from, int to, int key)
{
    int mid = from + ((to-from)/2);

    printf("from %d to %d: mid %d\n", from, to, mid);

    if (array[mid]->getKey() > key) {
        return InternalBinarySearch(array, from, mid-1, key);
    } else if (array[mid]->getKey() < key) {
        return InternalBinarySearch(array, mid+1, to, key);
    } else {
        return array[mid];
    }

    return NULL;
}

Node* BinarySearch(Node **array, int arraySize, int key)
{
    return InternalBinarySearch(array, 0, arraySize, key);
}
