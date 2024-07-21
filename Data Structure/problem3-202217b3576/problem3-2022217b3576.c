#include<stdio.h>

int stack[100], choice, n, top, x, i;

void push(void);
void pop(void);
void display(void);

int main() {
    // Initialize top to -1
    top = -1;

    printf("\n Enter the size of STACK[MAX=100]: ");
    scanf("%d", &n);

    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");

    do {
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\t EXIT POINT\n");
                break;
            default:
                printf ("\n\t Please Enter a Valid Choice (1/2/3/4)\n");
        }
    } while(choice != 4);

    return 0;
}

void push() {
    if(top >= n - 1) {
        printf("\n\tSTACK is overflow\n");
    } else {
        printf(" Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop() {
    if(top <= -1) {
        printf("\n\t Stack is underflow\n");
    } else {
        printf("\n\t The popped element is %d\n", stack[top]);
        top--;
    }
}

void display() {
    if(top >= 0) {
        printf("\n The elements in STACK are:\n");
        for(i = top; i >= 0; i--) {
            printf("\n%d", stack[i]);
        }
        printf("\n Press Next Choice\n");
    } else {
        printf("\n The STACK is empty\n");
    }
}
