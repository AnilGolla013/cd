#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack {
    int s[SIZE];
    int top;
} st;

int stfull() { return st.top == SIZE - 1; }
int stempty() { return st.top == -1; }

void push(int item) {
    st.s[++st.top] = item;
}

int pop() {
    return st.s[st.top--];
}

void display() {
    int i;
    if(stempty()) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements:\n");
    for(i = st.top; i >= 0; i--)
        printf("%d\n", st.s[i]);
}

int main() {
    int ch, item;
    st.top = -1;

    do {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                if(stfull()) printf("Stack Full\n");
                else {
                    printf("Enter item: ");
                    scanf("%d", &item);
                    push(item);
                }
                break;
            case 2:
                if(stempty()) printf("Stack Empty\n");
                else printf("Popped element = %d\n", pop());
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    } while(1);

    return 0;
}