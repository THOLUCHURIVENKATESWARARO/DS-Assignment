#include <stdio.h>
#include <stdlib.h>  // Added to include the exit() function
#define MAX 20  // Changed from 10 to 20 to match the size of array b

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n, p, e, i, pos;

void main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display\n6. Exit\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g);  // Added a space before %c to consume any leftover newline characters
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("\nInvalid location.");
    } else {
        for (i = pos; i < n - 1; i++) {
            b[i] = b[i + 1];
        }
        n--;
    }

    printf("\nThe elements after deletion: ");
    for (i = 0; i < n; i++) {
        printf("\t%d", b[i]);
    }
}

void search() {
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);

    int found = 0;
    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the %d position\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0) {
        printf("\nInvalid location.");
    } else {
        for (i = n; i > pos; i--) {
            b[i] = b[i - 1];
        }

        printf("\nEnter the element to insert: ");
        scanf("%d", &p);

        b[pos] = p;
        n++;
    }

    printf("\nThe list after insertion: ");
    display();
}

void display() {
    printf("\nThe elements of the list are: ");
    for (i = 0; i < n; i++) {
        printf("\n%d", b[i]);
    }
}

