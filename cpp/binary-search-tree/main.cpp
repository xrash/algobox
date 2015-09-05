#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main()
{
    BinaryTree<int,int> *btree = new BinaryTree<int,int>();

    btree->insert(10, 100);
    btree->insert(20, 200);
    btree->insert(30, 300);
    btree->insert(40, 400);
    btree->insert(50, 500);
    btree->insert(60, 600);
    btree->insert(70, 700);
    btree->insert(55, 555);
    btree->insert(51, 555);
    btree->insert(52, 555);
    btree->insert(53, 555);
    btree->insert(54, 555);

    btree->dump();

    btree->remove(52);

    btree->dump();

    printf("lookup: %d: %d\n", 5, btree->lookup(50));
}
