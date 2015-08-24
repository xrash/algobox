#include <stdio.h>
#include <stdlib.h>
#include "bsearch.h"
#include "node.h"

int main()
{
    int ARRAY_SIZE = 10;

    Node **array = (Node**) malloc(sizeof(Node*) * ARRAY_SIZE);

    array[0] = new Node(0, 0);
    array[1] = new Node(1, 100);
    array[2] = new Node(2, 200);
    array[3] = new Node(3, 300);
    array[4] = new Node(4, 400);
    array[5] = new Node(5, 500);
    array[6] = new Node(6, 600);
    array[7] = new Node(7, 700);
    array[8] = new Node(8, 800);
    array[9] = new Node(9, 900);
    array[10] = new Node(10, 1000);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("searching for %d\n", i);
        Node *found = BinarySearch(array, ARRAY_SIZE, i);
        printf("found %d => (%d, %d)\n\n", i, found->getKey(), found->getValue());
    }
}
