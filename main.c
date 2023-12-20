#include <stdio.h>
#include "operaciones.h"
#define CANT_CLASES 10


int main() {

    List * list1 = newList();
    insert(newNode(1), list1);
    insert(newNode(3), list1);
    insert(newNode(5), list1);
    insert(newNode(7), list1);
    insert(newNode(9), list1);
    insert(newNode(14), list1);

    List * list2 = newList();
    insert(newNode(1), list2);
    insert(newNode(2), list2);
    insert(newNode(4), list2);
    insert(newNode(7), list2);
    insert(newNode(14), list2);

    print(list1);
    print(list2);

    List * hashTable[CANT_CLASES];

    inicializarHash(hashTable);

    insertarHash(list2, hashTable);

    List * resultado = resta(list1, hashTable);

    printf("\nElementos de L1 no presentes en L2");
    print(resultado);


    return 0;
}
