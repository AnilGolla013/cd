#include<stdio.h>

int main() {
    int n, i, flag = 0;
    char vari[15], typ[15], expr[50], c;

    printf("Enter number of variables: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter variable[%d]: ", i);
        scanf(" %c", &vari[i]);
        printf("Enter type (f for float, i for int): ");
        scanf(" %c", &typ[i]);
        if(typ[i] == 'f') flag = 1;
    }

    printf("Enter expression ending with $: ");
    scanf("%s", expr);

    for(i = 0; expr[i] != '$'; i++) {
        if(expr[i] == '/') {
            flag = 1;
            break;
        }
    }

    for(i = 0; i < n; i++) {
        if(expr[0] == vari[i]) {
            if(flag && typ[i] != 'f')
                printf("Identifier %c must be float type\n", vari[i]);
            else
                printf("Datatype is correctly defined\n");
            break;
        }
    }

    return 0;
}



// 2
// a
// i
// b
// f
// a/b$