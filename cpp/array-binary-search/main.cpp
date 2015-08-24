#include <stdio.h>
#include <stdlib.h>
#include "bsearch.h"
#include "node.h"

int ARRAY_SIZE = 11;

void test(Node **array, int key)
{
    printf("searching for key %d\n", key);

    Node *found = BinarySearch(array, ARRAY_SIZE, key);

    if (found != NULL) {
        printf("found (%d, %d)\n\n", found->getKey(), found->getValue());
    } else {
        printf("key %d not found\n\n", key);
    }
}

int main()
{
    Node **array = (Node**) malloc(sizeof(Node*) * ARRAY_SIZE);

    array[0] = new Node(12, 0);
    array[1] = new Node(15, 100);
    array[2] = new Node(100, 200);
    array[3] = new Node(200, 300);
    array[4] = new Node(220, 400);
    array[5] = new Node(230, 500);
    array[6] = new Node(250, 600);
    array[7] = new Node(300, 700);
    array[8] = new Node(400, 800);
    array[9] = new Node(500, 900);
    array[10] = new Node(510, 1000);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        test(array, array[i]->getKey());
    }

    test(array, 0);
    test(array, 1);
    test(array, 600);
    test(array, 6100);
    test(array, 173);
    test(array, 6);
    test(array, 28);
}
