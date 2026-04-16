#include <stdio.h>
#include <ctype.h>
#include <string.h>

void FIRST(char c);
int count, n = 0;
char prodn[10][10], first[10];

int isPresent(char ch) {
    for (int i = 0; i < n; i++)
        if (first[i] == ch) return 1;
    return 0;
}

void FIRST(char c) {
    int j;
    if (!isupper(c)) {
        if (!isPresent(c))
            first[n++] = c;
        return;
    }

    for (j = 0; j < count; j++) {
        if (prodn[j][0] == c) {
            if (prodn[j][2] == '$') {
                if (!isPresent('$'))
                    first[n++] = '$';
            } else if (!isupper(prodn[j][2])) {
                if (!isPresent(prodn[j][2]))
                    first[n++] = prodn[j][2];
            } else {
                FIRST(prodn[j][2]);
            }
        }
    }
}

int main() {
    int i;
    char c;

    printf("How many productions? ");
    scanf("%d", &count);

    printf("Enter productions:\n");
    for (i = 0; i < count; i++)
        scanf("%s", prodn[i]);

    printf("Enter non-terminal: ");
    scanf(" %c", &c);

    FIRST(c);

    printf("FIRST(%c) = { ", c);
    for (i = 0; i < n; i++)
        printf("%c ", first[i]);
    printf("}\n");

    return 0;
}



// 3
// E=TR
// R=+TR
// R=$
// E