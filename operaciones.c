//
// Created by Administrador on 19/12/2023.
//

#include "operaciones.h"
#include <stdlib.h>
#include <stdio.h>
#define CANT_CLASES 10


Node *newNode(int data) {
    Node * aux = malloc(sizeof(Node));
    if(aux == NULL){
        exit (-1);
    }
    aux->data = data;
    aux->next = NULL;
    return aux;
}

List * newList(){
    List * aux = malloc(sizeof(List));
    if(aux == NULL){
        exit (-1);
    }
    aux->head = NULL;
    return aux;
}

void print(List * list){
    if(!list->head){
        printf("Lista vacia\n");
        return;
    }
    Node * aux = list->head;
    printf("\n");
    while(aux){
        printf("%d\t", aux->data);
        aux = aux->next;
    }
}

void insert(Node *node, List *list) {
    if(list->head == NULL){
        list->head = node;
        return;
    }
    Node * aux = list->head;
    while (aux->next){
        aux = aux->next;
    }
    aux->next = node;
}

List *resta(List *list1, List **hashTable) {
    List * resultadoResta = newList();
    Node * aux1 = list1->head;

    while(aux1){
        int pos = hashFunction(aux1->data);
        if(hashTable[pos] != NULL){
            Node * auxL2 = hashTable[pos]->head;
            while(auxL2 && auxL2->data != aux1->data){
                auxL2 = auxL2->next;
            }
            if(!auxL2){
                insert(newNode(aux1->data), resultadoResta);
            }
            aux1 = aux1->next;
        }
    }
    return resultadoResta;
}

void inicializarHash(List ** hashTable) {
    for(int i=0; i<CANT_CLASES; i++){
        hashTable[i] = newList();
    }
}

int hashFunction(int data) {
    return data%CANT_CLASES;
}

void insertarHash(List *list, List ** hashTable) {
    Node * aux = list->head;
    while (aux){
        insert(newNode(aux->data),hashTable[hashFunction(aux->data)]);
        aux = aux->next;
    }
}
