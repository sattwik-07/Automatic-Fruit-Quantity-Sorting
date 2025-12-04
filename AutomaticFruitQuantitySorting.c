/* merge_sort_fruits.c
   Compile: gcc -o merge_sort_fruits merge_sort_fruits.c
   Run: ./merge_sort_fruits
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64

typedef struct {
    char name[MAX_NAME_LEN];
    long quantity; /* Use long for quantity; change to double if needed for weights */
} Fruit;

/* Merge two sorted subarrays arr[l..m] and arr[m+1..r] */
void merge(Fruit arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    /* create temp arrays */
    Fruit *L = (Fruit *)malloc(n1 * sizeof(Fruit));
    Fruit *R = (Fruit *)malloc(n2 * sizeof(Fruit));

    if (!L || !R) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    /* Merge keeping stability: if quantities are equal, take from L first */
    while (i < n1 && j < n2) {
        if (L[i].quantity <= R[j].quantity) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    /* Copy remaining elements of L[], if any */
    while (i < n1) arr[k++] = L[i++];

    /* Copy remaining elements of R[], if any */
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void merge_sort(Fruit arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main(void) {
    int n;
    printf("Enter number of fruit entries: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of entries.\n");
        return 1;
    }

    /* consume trailing newline */
    getchar();

    Fruit *arr = (Fruit *)malloc(n * sizeof(Fruit));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter fruit entries as: <Name> <Quantity>\n");
    printf("Example: Apple 12\n");

    for (int i = 0; i < n; i++) {
        char line[256];
        printf("Entry %d: ", i + 1);
        if (!fgets(line, sizeof(line), stdin)) {
            fprintf(stderr, "Error reading input\n");
            free(arr);
            return 1;
        }
        /* strip newline */
        line[strcspn(line, "\n")] = 0;

        /* parse name and quantity; allow names without spaces.
           If names can have spaces, a different input method is needed. */
        char name[MAX_NAME_LEN];
        long qty;
        if (sscanf(line, "%63s %ld", name, &qty) >= 1) {
            strncpy(arr[i].name, name, MAX_NAME_LEN);
            arr[i].name[MAX_NAME_LEN - 1] = '\0';
            arr[i].quantity = qty;
        } else {
            fprintf(stderr, "Invalid format. Please provide: Name Quantity\n");
            i--; /* retry this entry */
        }
    }

    /* Sort using merge sort */
    merge_sort(arr, 0, n - 1);

    /* Output sorted results */
    printf("\nSorted fruit list by quantity (ascending):\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s %10ld\n", arr[i].name, arr[i].quantity);
    }

    free(arr);
    return 0;
}
