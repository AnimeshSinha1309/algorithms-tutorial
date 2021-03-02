#include <stdio.h>
#include <stdlib.h>

int* list;

int main() {
    int n; 
    scanf("%d", &n);

    list = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", list + i);
    }

    printf("Your Inputs are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}
