#include <stdio.h>
#include <stdlib.h>

void lire(int T[], int N) {
    for (int i = 0; i < N; i++) {
        printf("T[%d]: ", i);
        scanf("%d", &T[i]);
    }
}

void show(int T[], int N) {
    for (int i = 0; i < N; i++) {
        printf("T[%d] = %d\n", i, T[i]);
    }
}

int max(int T[], int N) {
  // the main idea is to do less work so we asigne max cariable to the first index and the compare it to the rest of the array
    int max = T[0];
    for (int i = 1; i < N; i++) {
        if (T[i] > max)
            max = T[i];
    }
    return max;
}

void reverse(int T[], int N) {
    int j = N - 1;
    for (int i = 0; i < N / 2; i++) {
    // we use the swap variable consept you dumb-shit
    int temp = T[i];
        T[i] = T[j];
        T[j] = temp;
        j--;
    }
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    
    int T[N];
    int choice;
    
    do {
        printf("\nMenu:\n");
        printf("1. Input array elements\n");
        printf("2. Display array\n");
        printf("3. Find maximum element\n");
        printf("4. Reverse array\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                lire(T, N);
                break;
            case 2:
                show(T, N);
                break;
            case 3:
                printf("The largest element is %d\n", max(T, N));
                break;
            case 4:
                reverse(T, N);
                printf("Array reversed.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return EXIT_SUCCESS;
}
