#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct table {
    char var[10];
    int value;
} tbl[20];

int n = 0, i, j;

int search(char v[]) {
    for(i = 0; i < n; i++)
        if(strcmp(tbl[i].var, v) == 0) return i;
    return -1;
}

void display() {
    printf("\nVARIABLE\tVALUE\n");
    for(i = 0; i < n; i++)
        printf("%s\t\t%d\n", tbl[i].var, tbl[i].value);
}

void create() {
    printf("Enter number of entries: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter variable and value: ");
        scanf("%s%d", tbl[i].var, &tbl[i].value);

        for(j = 0; j < i; j++) {
            if(strcmp(tbl[i].var, tbl[j].var) == 0) {
                printf("Variable already exists. Re-enter\n");
                i--;
                break;
            }
        }
    }
}

void insert() {
    if(n >= 20) {
        printf("Table full\n");
        return;
    }

    printf("Enter variable and value: ");
    scanf("%s%d", tbl[n].var, &tbl[n].value);

    if(search(tbl[n].var) != -1) {
        printf("Variable already exists\n");
        return;
    }
    n++;
}

void modify() {
    char v[10];
    int pos;

    printf("Enter variable to modify: ");
    scanf("%s", v);

    pos = search(v);
    if(pos == -1) {
        printf("Variable not found\n");
        return;
    }

    printf("Enter new variable name and value: ");
    scanf("%s%d", tbl[pos].var, &tbl[pos].value);
}

int main() {
    int ch, pos;
    char v[10];

    do {
        printf("\n1.Create\n2.Insert\n3.Modify\n4.Search\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create(); break;
            case 2: insert(); break;
            case 3: modify(); break;
            case 4:
                printf("Enter variable to search: ");
                scanf("%s", v);
                pos = search(v);
                if(pos == -1) printf("Variable not found\n");
                else printf("Found at position %d with value %d\n", pos + 1, tbl[pos].value);
                break;
            case 5: display(); break;
            case 6: exit(0);
        }
    } while(ch != 6);

    return 0;
}