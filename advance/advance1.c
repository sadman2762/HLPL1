/*
Source of problem: https://progcont.hu/progcont/100005/?locale=en&pid=272
*/

#include <stdio.h>

int main() {
    int c, quote_open = 0;

    while ((c = getchar()) != EOF) {
        if (c == '"') {
            printf("%s", quote_open ? "''" : "``");
            quote_open = !quote_open;
        } else {
            putchar(c);
        }
    }

    return 0;
}