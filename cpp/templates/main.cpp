#include <stdio.h>
#include "node.h"

int main()
{
    int i = 5;

    Node<int>* one = new Node<int>(1, 200);
    Node<int*>* two = new Node<int*>(2, &i);

    printf("asdasdx %d\n", one->getValue());
    printf("asdasdx %d\n", *(two->getValue()));
}
