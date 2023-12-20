//
// Created by Administrador on 19/12/2023.
//

#ifndef OPERACIONESSETS_OPERACIONES_H
#define OPERACIONESSETS_OPERACIONES_H

typedef struct node{
    int data;
    struct node * next;
}Node;

typedef struct list{
    Node * head;
    int size;
}List;

Node * newNode(int data);
List * newList();
void insert(Node * node, List * list);
void print(List * list);

void inicializarHash(List ** hashTable);
void insertarHash(List * list, List ** hashTable);
int hashFunction(int data);

List * resta(List * list1, List ** hashTable);
List * interseccion(List * list, List ** hashTable);
void subconjunto(List * list, List ** hashTable, int sizeHashTable);

#endif //OPERACIONESSETS_OPERACIONES_H
