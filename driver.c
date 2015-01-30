#include <stdio.h>
#include <stdlib.h>

extern char* html;

int main() {
    fputs(html, stdout);
    return EXIT_SUCCESS;
}
