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
    insert(newNode(3), list2);
    insert(newNode(5), list2);
    insert(newNode(9), list2);
    insert(newNode(14), list2);

    print(list1);
    print(list2);

    List * hashTable[CANT_CLASES];

    inicializarHash(hashTable);

    insertarHash(list2, hashTable);

    List * resultadoResta = resta(list1, hashTable);
    List * resultadoInterseccion = interseccion(list1, hashTable);
    List * resultadoUnion = unionOperation(list1, hashTable);

    printf("\nElementos de L1 no presentes en L2");
    print(resultadoResta);

    printf("\nInterseccion de lista 1 con lista 2");
    print(resultadoInterseccion);

    subconjunto(list1, hashTable, list2->size);

    printf("\nUnion de lista 1 con lista 2");
    print(resultadoUnion);

    return 0;
}
