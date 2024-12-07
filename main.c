#include <stdio.h>
#include "file_prioritaire.h"

int main() {
    int p;
    printf("Enter the number of priorities: ");
    scanf("%d", &p);

    FilePrioritaire F = create_file_prioritaire(p);

    while (1) {
        int choice, priority;
        float value;

        printf("\nMenu:\n");
        printf("1. Enfiler (Enqueue)\n");
        printf("2. Defiler (Dequeue)\n");
        printf("3. Display all files\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter priority (1-%d): ", p);
            scanf("%d", &priority);
            if (priority < 1 || priority > p) {
                printf("Invalid priority!\n");
                break;
            }
            printf("Enter value to enqueue: ");
            scanf("%f", &value);
            enfiler_prioritaire(&F, value, priority);
            break;
            case 2:
                defiler_prioritaire(&F);
            break;
            case 3:
                display_all_files(F);
            break;
            case 4:
                printf("Exiting...\n");
            return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
