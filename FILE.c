
#include "file.h"
#include <stdlib.h>
#include <stdio.h>

// Fonction pour créer un nouveau nœud
node *cree_node(float e) {
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) {
        return NULL;  // Échec d'allocation mémoire
    }
    new_node->data = e;
    new_node->next = NULL;  // Le pointeur suivant est NULL pour le dernier nœud
    return new_node;
}

// Fonction pour créer une file vide
File empty_file() {
    File F;
    F.tete = NULL;  // La tête de la file est initialement NULL
    F.arriere = NULL;  // L'arrière de la file est initialement NULL
    return F;
}

// Fonction pour vérifier si la file est vide
bool est_vide(File F) {
    return F.tete == NULL;  // Si tete est NULL, la file est vide
}

// Fonction pour obtenir la longueur de la file
int longueur(File F) {
    int len = 0;
    node *temp = F.tete;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Fonction pour ajouter un élément à la fin de la file
void enfiler(File *F, float e) {
    node *new_node = cree_node(e);
    if (new_node == NULL) {
        return;  // Échec d'allocation mémoire
    }

    if (est_vide(*F)) {
        // Si la file est vide, la tête et l'arrière pointent vers le nouveau nœud
        F->tete = new_node;
        F->arriere = new_node;
    } else {
        // Sinon, ajouter le nouveau nœud après l'arrière actuel
        F->arriere->next = new_node;  // Mettre à jour le pointeur suivant de l'arrière
        F->arriere = new_node;  // Mettre à jour l'arrière pour pointer sur le nouveau dernier nœud
    }
}

// Fonction pour supprimer le premier nœud de la file
void defiler(File *F) {
    if (est_vide(*F)) {
        return;  // Aucun élément à supprimer
    }

    node *temp = F->tete;
    F->tete = temp->next;  // Déplacer la tête vers le nœud suivant

    if (F->tete == NULL) {
        // Si la file est maintenant vide, réinitialiser l'arrière à NULL
        F->arriere = NULL;
    }

    free(temp);  // Libérer la mémoire du nœud supprimé
}

// Fonction pour retourner les données du premier nœud de la file
float premier(File F) {
    if (est_vide(F)) {
        return -1;  // Retourner une valeur sentinelle pour une file vide
    }
    return F.tete->data;  // Retourner les données du premier nœud
}

// Fonction pour afficher tous les éléments de la file
void display_file(File F) {
    if (est_vide(F)) {
        printf("La file est vide.\n");
        return;
    }
    node *current = F.tete;
    while (current) {
        printf("%.2f ", current->data);
        current = current->next;
    }
    printf("\n");
}
