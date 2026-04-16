#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0, error = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();

int main()
{
    printf("Enter the expression: ");
    scanf("%s", input);

    E();

    if(input[i] == '\0' && error == 0)
        printf("String is Accepted\n");
    else
        printf("String is Rejected\n");

    return 0;
}

// E -> T E'
void E()
{
    T();
    Eprime();
}

// E' -> + T E' | e
void Eprime()
{
    if(input[i] == '+')
    {
        i++;
        T();
        Eprime();
    }
}

// T -> F T'
void T()
{
    F();
    Tprime();
}

// T' -> * F T' | e
void Tprime()
{
    if(input[i] == '*')
    {
        i++;
        F();
        Tprime();
    }
}

// F -> (E) | id
void F()
{
    if(isalnum(input[i]))   // id
    {
        i++;
    }
    else if(input[i] == '(')
    {
        i++;
        E();

        if(input[i] == ')')
        {
            i++;
        }
        else
        {
            error = 1;
        }
    }
    else
    {
        error = 1;
    }
}


//input
// a+b*c