//
// Created by FAHD on 08/12/2024.
//
#include "file.h"
#include <stdlib.h>
#include <stdio.h>

// Function to create a new node
node *cree_node(float e) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;  // Memory allocation failed
    }
    new_node->data = e;
    new_node->next = NULL;  // The next pointer is NULL for the last node
    return new_node;
}

// Function to create an empty file (queue)
File empty_file() {
    File F;
    F.tete = NULL;  // Front of the queue is initially NULL
    F.arriere = NULL;  // Rear of the queue is initially NULL
    return F;
}

// Function to check if the file (queue) is empty
bool est_vide(File F) {
    return F.tete == NULL;  // If tete is NULL, the queue is empty
}

// Function to get the length of the file (queue)
int longueur(File F) {
    int len = 0;
    node *temp = F.tete;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Function to add an element to the end of the file (queue)
void enfiler(File *F, float e) {
    node *new_node = cree_node(e);
    if (new_node == NULL) {
        return;  // Memory allocation failed
    }

    if (est_vide(*F)) {
        // If the queue is empty, both tete and arriere point to the new node
        F->tete = new_node;
        F->arriere = new_node;
    } else {
        // Otherwise, add the new node after the current arriere
        F->arriere->next = new_node;  // Update the current rear node's next pointer
        F->arriere = new_node;  // Update arriere to point to the new last node
    }
}

// Function to remove the first node from the file (queue)
void defiler(File *F) {
    if (est_vide(*F)) {
        return;  // No elements to remove
    }

    node *temp = F->tete;
    F->tete = temp->next;  // Move tete to the next node

    if (F->tete == NULL) {
        // If the queue is now empty, reset arriere to NULL
        F->arriere = NULL;
    }

    free(temp);  // Free the memory of the removed node
}

// Function to return the data of the first node in the file (queue)
float premier(File F) {
    if (est_vide(F)) {
        return -1;  // Return a sentinel value for an empty file
    }
    return F.tete->data;  // Return the data of the first node
}
void display_file(File F) {
    if (est_vide(F)) {
        printf("The queue is empty.\n");
        return;
    }
    node *current = F.tete;
    while (current) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}