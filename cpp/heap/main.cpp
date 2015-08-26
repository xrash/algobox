#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main()
{
    Heap<int,int> *heap = new Heap<int,int>(10);

    heap->dump();
    heap->insert(15, 1);
    heap->dump();
    heap->insert(1000, 2);
    heap->dump();
    heap->insert(300, 3);
    heap->dump();
    heap->insert(670, 4);
    heap->dump();
    heap->insert(500, 5);
    heap->dump();
    heap->insert(70, 6);
    heap->dump();

    heap->insert(80, 6);
    heap->dump();

    heap->insert(100, 6);
    heap->dump();

    heap->insert(101, 6);
    heap->dump();

    heap->insert(205, 6);
    heap->dump();

    heap->insert(400, 6);
    heap->dump();

    heap->insert(4111100, 6);
    heap->dump();

    heap->insert(14111100, 6);
    heap->dump();

    heap->insert(403, 6);
    heap->insert(403, 6);
    heap->insert(403, 6);
    heap->insert(403, 6);
    heap->insert(403, 6);
    heap->insert(403, 6);
    heap->dump();

    HeapNode<int,int>* popped = heap->pop();
    printf("popped: %d\n", popped->key);

    popped = heap->pop();
    printf("popped: %d\n", popped->key);

    popped = heap->pop();
    printf("popped: %d\n", popped->key);

    popped = heap->pop();
    printf("popped: %d\n", popped->key);

    popped = heap->pop();
    printf("popped: %d\n", popped->key);

    popped = heap->pop();
    printf("popped: %d\n", popped->key);

    popped = heap->pop();
    if (popped != NULL) {
        printf("popped: %d\n", popped->key);
    }

    printf("\n");

    heap->dump();
}
