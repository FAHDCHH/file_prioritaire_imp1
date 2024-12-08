
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
    node *tete;
    node *arriere;
} File;

node *cree_node(float e);
File empty_file();
bool est_vide(File F);
int longueur(File F);
void enfiler(File *F, float e);
void defiler(File *F);
float premier(File F);
void display_file(File F);

#endif //FILE_H
