#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char s[]) {
    char *k[] = {"for","while","int","float","char","void"};
    for(int i=0;i<6;i++)
        if(strcmp(s,k[i])==0) return 1;
    return 0;
}

int main() {
    FILE *f;
    char c, str[20];
    int num[100], n=0, lines=0, i;

    f = fopen("input","r");
    while((c=getc(f)) != EOF) {
        if(isdigit(c)) {
            int val = 0;
            do {
                val = val*10 + (c-'0');
                c = getc(f);
            } while(isdigit(c));
            num[n++] = val;
            if(c != EOF) ungetc(c,f);
        }
        else if(isalpha(c)) {
            i = 0;
            do {
                str[i++] = c;
                c = getc(f);
            } while(isalnum(c) || c=='_' || c=='$');
            str[i] = '\0';

            if(isKeyword(str))
                printf("%s is a keyword\n", str);
            else
                printf("%s is an identifier\n", str);

            if(c != EOF) ungetc(c,f);
        }
        else if(c == '\n') lines++;
        else if(c!=' ' && c!='\t')
            printf("%c ", c);
    }
    fclose(f);

    printf("\nNumbers are: ");
    for(i=0;i<n;i++) printf("%d ", num[i]);

    printf("\nTotal lines = %d\n", lines);
    return 0;
}