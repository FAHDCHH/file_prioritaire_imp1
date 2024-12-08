//
// Created by FAHD on 08/12/2024.
//
#ifndef FILE_PRIORITAIRE_H
#define FILE_PRIORITAIRE_H

#include "file.h"  // Include the original file.h for the File structure

typedef struct FilePrioritaire {
    File *files;
    int p;
} FilePrioritaire;


FilePrioritaire create_file_prioritaire(int p);
void enfiler_prioritaire(FilePrioritaire *F, float e, int priority);
void defiler_prioritaire(FilePrioritaire *F);
float premier_prioritaire(FilePrioritaire F);
int max_priority(FilePrioritaire F);
void display_all_files(FilePrioritaire F);

#endif // FILE_PRIORITAIRE_H
