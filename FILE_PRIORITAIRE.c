//
// Created by FAHD on 08/12/2024.
//
#include "file_prioritaire.h"
#include <stdlib.h>
#include <stdio.h>

// Function to create a FilePrioritaire with p priorities
FilePrioritaire create_file_prioritaire(int p) {
    FilePrioritaire F;
    F.p = p;
    F.files = (File *)malloc(p * sizeof(File));  // Create an array of files

    // Initialize each file in the array
    for (int i = 0; i < p; i++) {
        F.files[i] = empty_file();  // Initialize an empty file for each priority
    }

    return F;
}

// Function to enqueue an element with a specific priority
void enfiler_prioritaire(FilePrioritaire *F, float e, int priority) {
    if (priority < 1 || priority > F->p) {
        printf("Error: Invalid priority.\n");
        return;
    }

    // Enqueue in the file corresponding to the given priority
    enfiler(&F->files[priority - 1], e);
}

// Function to dequeue the element with the highest priority
void defiler_prioritaire(FilePrioritaire *F) {
    int max_priority_value = max_priority(*F);
    if (max_priority_value == -1) {
        printf("Error: All queues are empty.\n");
        return;
    }

    // Remove from the highest priority file
    defiler(&F->files[max_priority_value]);
}

// Function to return the first element with the highest priority
float premier_prioritaire(FilePrioritaire F) {
    int max_priority_value = max_priority(F);
    if (max_priority_value == -1) {
        printf("Error: All queues are empty.\n");
        return -1;  // Return an error value for empty queues
    }

    return premier(F.files[max_priority_value]);
}

// Function to get the maximum priority with a non-empty queue
int max_priority(FilePrioritaire F) {
    for (int i = F.p - 1; i >= 0; i--) {
        if (!est_vide(F.files[i])) {
            return i;  // Return the index of the first non-empty file (highest priority)
        }
    }
    return -1;  // Return -1 if all queues are empty
}
void display_all_files(FilePrioritaire F) {
    for (int i = 0; i < F.p; i++) {
        printf("Priority %d: ", i + 1);
        display_file(F.files[i]);
    }
}