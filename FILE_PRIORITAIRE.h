//
// Created by FAHD on 08/12/2024.
//
#ifndef FILE_PRIORITAIRE_H
#define FILE_PRIORITAIRE_H

#include "file.h"  // Include the original file.h for the File structure

typedef struct FilePrioritaire {
    File *files;  // Array of queues, each corresponding to a priority
    int p;         // Number of priorities
} FilePrioritaire;

// Function to create a FilePrioritaire with p priorities
FilePrioritaire create_file_prioritaire(int p);

// Function to enqueue an element with a specific priority
void enfiler_prioritaire(FilePrioritaire *F, float e, int priority);

// Function to dequeue the element with the highest priority
void defiler_prioritaire(FilePrioritaire *F);

// Function to return the first element with the highest priority
float premier_prioritaire(FilePrioritaire F);

// Function to get the maximum priority
int max_priority(FilePrioritaire F);

void display_all_files(FilePrioritaire F);

#endif // FILE_PRIORITAIRE_H
