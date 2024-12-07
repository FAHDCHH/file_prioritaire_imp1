//
// Created by FAHD on 08/12/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#ifndef FILE_H
#define FILE_H

typedef struct node {
    float data;
    struct node *next;
} node;

typedef struct File {
    node *tete;   // Front of the queue
    node *arriere; // Rear of the queue
} File;

node *cree_node(float e);
File empty_file();
bool est_vide(File F);
int longueur(File F);
void enfiler(File *F, float e);  // Always add to the end of the linked list (queue)
void defiler(File *F);  // Remove the oldest element (front)
float premier(File F);
void display_file(File F);

#endif //FILE_H
