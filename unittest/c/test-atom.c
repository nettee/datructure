#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

int getword(FILE *, char *, int);
void hashin(char *, FILE *);

void print_bucket();

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s: %s\n", argv[0], argv[i], strerror(errno));
            return 1;
        } else {
            hashin(argv[i], fp);
            fclose(fp);
        }
    }
    if (argc == 1) {
        hashin(NULL, stdin);
    }
    return 0;
}

void hashin(char *name, FILE *fp)
{
    char word[128];
    while(getword(fp, word, sizeof word)) {
        atom_new(word);
    }
    print_bucket();
}

/* copy from shtl/c/double.c */
int getword(FILE *fp, char *buf, int size) 
{
    assert(buf != NULL);
    char c;
    int i = 0;
    c = getc(fp);
    /* scan forward to a nonspace charactor */
    for ( ; c != EOF && isspace(c); c = getc(fp)) {
        ;
    }
    /* scan and copy a word into buf */
    for ( ; c != EOF && !isspace(c); c = getc(fp)) {
        if (i < size - 1) {
            buf[i++] = tolower(c);
        }
    }
    if (i < size) {
        buf[i] = '\0';
    }

    if (c != EOF) {
        ungetc(c, fp);
    }
    return buf[0] != '\0';
}
