#include <stdio.h>
#include <ctype.h>
#include <string.h>

void keyword(char str[]) {
    if(strcmp("for",str)==0 || strcmp("while",str)==0 || strcmp("do",str)==0 ||
       strcmp("int",str)==0 || strcmp("float",str)==0 || strcmp("char",str)==0 ||
       strcmp("double",str)==0 || strcmp("static",str)==0 || strcmp("switch",str)==0 ||
       strcmp("case",str)==0 || strcmp("void",str)==0)
        printf("%s -> Keyword\n", str);
    else
        printf("%s -> Identifier\n", str);
}

int main() {
    FILE *fp;
    char ch, str[20];
    int i;

    fp = fopen("input.c", "r");
    if(!fp) {
        printf("File not found\n");
        return 0;
    }

    while((ch = fgetc(fp)) != EOF) {
        if(isalpha(ch)) {
            i = 0;
            str[i++] = ch;
            while(isalnum(ch = fgetc(fp)) || ch == '_')
                str[i++] = ch;
            str[i] = '\0';
            fseek(fp, -1, SEEK_CUR);
            keyword(str);
        }
        else if(isdigit(ch)) {
            i = 0;
            str[i++] = ch;
            while(isdigit(ch = fgetc(fp)) || ch == '.')
                str[i++] = ch;
            str[i] = '\0';
            fseek(fp, -1, SEEK_CUR);
            printf("%s -> Constant\n", str);
        }
        else if(ch == '/' && (ch = fgetc(fp)) == '/') {
            printf("//");
            while((ch = fgetc(fp)) != '\n')
                putchar(ch);
            printf(" -> Comment\n");
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=') {
            printf("%c -> Operator\n", ch);
        }
    }

    fclose(fp);
    return 0;
}