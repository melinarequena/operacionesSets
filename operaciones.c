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
    aux->size = 0;
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
        list->size = 1;
        return;
    }
    Node * aux = list->head;
    while (aux->next){
        aux = aux->next;
    }
    aux->next = node;
    list->size++;
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

List *interseccion(List *list, List **hashTable) {
    List * resultado = newList();
    Node * aux1 = list->head;
    while (aux1){
        int pos = hashFunction(aux1->data);
        if(hashTable[pos] != NULL){
            Node * aux2 = hashTable[pos]->head;
            while (aux2 && aux1->data != aux2->data){
                aux2 = aux2->next;
            }
            if(aux2 && aux1->data == aux2->data){
                insert(newNode(aux2->data), resultado);
            }
            aux1 = aux1->next;
        }
    }
    return resultado;
}

void subconjunto(List *list, List **hashTable, int sizeHashTable) {
    int cont1 = 0, cont2 = 0;
    Node * aux1 = list->head;
    while (aux1){
        int pos = hashFunction(aux1->data);
        if(hashTable[pos] != NULL){
            Node * aux2 = hashTable[pos]->head;
            while (aux2 && aux1->data != aux2->data){
                aux2 = aux2->next;
            }
            if(aux2 && aux1->data == aux2->data){
                cont1++;
                cont2++;
            }
        }
        aux1 = aux1->next;
    }
    if(list->size == cont1){
        printf("\nLa lista 1 es un subconjunto de la lista 2\n");
    }else
        if(sizeHashTable == cont2){
            printf("\nLa lista 2 es un subconjunto de la lista 1\n");
        }else{
            printf("\nNinguna lista es subconjunto\n");
        }
}

List *unionOperation(List *list, List **hashTable) {
    List * resultado = newList();
    Node * aux1 = list->head;
    while(aux1){
        int pos = hashFunction(aux1->data);
        if(hashTable[pos]->head){
            Node * aux2 = hashTable[pos]->head;
            while (aux2){
                if(aux1->data != aux2->data){
                    insert(newNode(aux2->data), resultado);
                }
                aux2 = aux2->next;
            }
        }
        insert(newNode(aux1->data), resultado);
        aux1 = aux1->next;
    }
    return resultado;
}
