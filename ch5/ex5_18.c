/*Make dcl recover from input errors
*Author:Sagar
*Create:18 April 2024
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100

enum { NAME, PARENS, BRACKETS };

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buf

int getch(void)     // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int gettoken(void)  // return next token
{
    int c;
    char *p = buf;

    while ((c = getch()) == ' ' || c == '\t')
        ;

    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(p, "()");
            return PARENS;
        } else {
            ungetch(c);
            return '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return NAME;
    } else {
        return c;
    }
}

int tokentype;              // type of last token
char token[MAXTOKEN];       // last token string
char name[MAXTOKEN];        // identifier name
char datatype[MAXTOKEN];    // data type = char, int, etc.
char out[1000];             // output string

void dcl(void);
void dirdcl(void);

// dcl: parse a declarator
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; )  // count *'s
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

// dirdcl: parse a direct declarator
void dirdcl(void)
{
    int type;

    if (tokentype == '(') {            // ( dcl )
        dcl();
        if (tokentype != ')') {
            printf("error: missing )\n");
            while ((type = getch()) != '\n') // skip until newline
                ;
            return;
        }
    } else if (tokentype == NAME)     // variable name
        strcpy(name, token);
    else {
        printf("error: expected name or (dcl)\n");
        while ((type = getch()) != '\n') // skip until newline
            ;
        return;
    }

    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

int main(void)
{
    while (gettoken() != EOF) {    // 1st token on line
        strcpy(datatype, token);   // is the datatype
        out[0] = '\0';
        dcl();                     // parse rest of line
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
/*Required Header Files*/
