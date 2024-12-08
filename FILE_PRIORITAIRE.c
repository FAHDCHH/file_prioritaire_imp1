//
// Created by FAHD on 08/12/2024.
//
#include "file_prioritaire.h"
#include <stdlib.h>
#include <stdio.h>

// Fonction pour créer une FilePrioritaire avec p priorités
FilePrioritaire create_file_prioritaire(int p) {
    FilePrioritaire F;
    F.p = p;
    F.files = (File *)malloc(p * sizeof(File));  // Crée un tableau de files

    // Initialiser chaque file dans le tableau
    for (int i = 0; i < p; i++) {
        F.files[i] = empty_file();  // Initialiser une file vide pour chaque priorité
    }

    return F;
}

// Fonction pour enfiler un élément avec une priorité spécifique
void enfiler_prioritaire(FilePrioritaire *F, float e, int priority) {
    if (priority < 1 || priority > F->p) {
        printf("Erreur : Priorité invalide.\n");
        return;
    }

    // Enfiler dans la file correspondant à la priorité donnée
    enfiler(&F->files[priority - 1], e);
}

// Fonction pour défiler l'élément avec la plus haute priorité
void defiler_prioritaire(FilePrioritaire *F) {
    int max_priority_value = max_priority(*F); // Pourquoi passer un pointeur ?
    if (max_priority_value == -1) {
        printf("Erreur : Toutes les files sont vides.\n");
        return;
    }

    // Supprimer de la file avec la priorité la plus haute
    defiler(&F->files[max_priority_value]);
}

// Fonction pour retourner le premier élément avec la plus haute priorité
float premier_prioritaire(FilePrioritaire F) {
    int max_priority_value = max_priority(F);
    if (max_priority_value == -1) {
        printf("Erreur : Toutes les files sont vides.\n");
        return -1;  // Retourne une valeur d'erreur pour les files vides
    }

    return premier(F.files[max_priority_value]);
}

// Fonction pour obtenir la priorité maximale ayant une file non vide
int max_priority(FilePrioritaire F) {
    for (int i = F.p - 1; i >= 0; i--) {
        if (!est_vide(F.files[i])) {
            return i;  // Retourne l'indice de la première file non vide (priorité la plus haute)
        }
    }
    return -1;  // Retourne -1 si toutes les files sont vides
}

// Fonction pour afficher toutes les files
void display_all_files(FilePrioritaire F) {
    for (int i = 0; i < F.p; i++) {
        printf("Priorite %d : ", i + 1);
        display_file(F.files[i]);
    }
}