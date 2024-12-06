#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char* a, char* b) {
    char temp[100];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char* arr[], int low, int high) {
    char* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void print_names(char* arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n, choice;
    char** names;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter Names\n");
        printf("2. Sort Names\n");
        printf("3. Display Names\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of names: ");
                scanf("%d", &n);

                names = (char**)malloc(n * sizeof(char*));
                for (int i = 0; i < n; i++) {
                    names[i] = (char*)malloc(100 * sizeof(char));
                    printf("Enter name %d: ", i + 1);
                    scanf("%s", names[i]);
                }
                break;

            case 2:
                if (names) {
                    quicksort(names, 0, n - 1);
                    printf("Names sorted.\n");
                } else {
                    printf("No names entered.\n");
                }
                break;

            case 3:
                if (names) {
                    printf("Names list:\n");
                    print_names(names, n);
                } else {
                    printf("No names entered.\n");
                }
                break;

            case 4:
                if (names) {
                    for (int i = 0; i < n; i++) {
                        free(names[i]);
                    }
                    free(names);
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
