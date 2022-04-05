//
// Created by Maor Buskila on 25/03/2022.
//

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
    int i;
    FILE *out = stdout;
    FILE *in = stdin;
    FILE *err = stderr;
    char ch;
    int converted = 0;
    int debug = 0;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-D") == 0) {
            fprintf(out, "debug mode enabeld!\n");
            debug = 1;
        }
    }

    printf("insert something:\n");
    fflush(stdout);
    int d = 0;
    while ((ch = fgetc(in)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            if (debug) {
                fprintf(err, "%d ", ch);
                fprintf(err, "%d\n", '.');
            }
            fprintf(out, ".");
            converted++;
        } else if (ch != 10) {
            if (debug) {
                fprintf(err, "%d %d\n", ch, ch);
            }
            fprintf(out, "%c", ch);
        } else fprintf(out, "%c", '\n');
    }

    if (debug)
        fprintf(stderr, "number of converted letters: %d\n", converted);
    return 0;
}
