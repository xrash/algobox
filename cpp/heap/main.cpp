#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#include "node.h"

int main()
{
    Heap<Node<int>*> *heap = new Heap<Node<int>*>(10);

    Node<int>* one = new Node<int>(15, 1);
    Node<int>* two = new Node<int>(1000, 2);
    Node<int>* three = new Node<int>(300, 3);
    Node<int>* four = new Node<int>(670, 4);
    Node<int>* five = new Node<int>(500, 5);
    Node<int>* six = new Node<int>(70, 6);

    heap->dump();
    heap->insert(one);
    heap->dump();
    heap->insert(two);
    heap->dump();
    heap->insert(three);
    heap->dump();
    heap->insert(four);
    heap->dump();
    heap->insert(five);
    heap->dump();
    heap->insert(six);
    heap->dump();

    Node<int>* popped = heap->pop();
    printf("popped: %d\n", popped->getKey());

    popped = heap->pop();
    printf("popped: %d\n", popped->getKey());

    popped = heap->pop();
    printf("popped: %d\n", popped->getKey());

    popped = heap->pop();
    printf("popped: %d\n", popped->getKey());

    popped = heap->pop();
    printf("popped: %d\n", popped->getKey());

    popped = heap->pop();
    printf("popped: %d\n", popped->getKey());

    popped = heap->pop();
    if (popped != NULL) {
        printf("popped: %d\n", popped->getKey());
    }

    printf("\n");

    heap->dump();
}
