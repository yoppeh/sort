
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"

typedef void (*sort_func_t)(int *a, int n);

int *a = NULL;
int n = 0;
sort_func_t sort_func = NULL;

void show_syntax(char *s) {
    printf("syntax:\n\t%s algorithm count\n", s);
    printf("algorithm:\n");
    printf("\tb ... bubble sort\n");
    printf("\th ... heap sort\n");
    printf("\ti ... insertion sort\n");
    printf("\tm ... merge sort\n");
    printf("\tq ... quick sort\n");
    printf("count = number of random array elements\n");
}

void parse_args(int ac, char **av) {
    if (ac != 3) {
        show_syntax(av[0]);
        return;
    }
    n = atoi(av[2]);
    printf("count = %i\n", n);
    switch (av[1][0]) {
        case 'b':
        case 'B':
            printf("using bubble sort\n");
            sort_func = sort_bubble;
            return;
        case 'h':
        case 'H':
            printf("using heap sort\n");
            sort_func = sort_heap;
            return;
        case 'i':
        case 'I':
            printf("using insertion sort\n");
            sort_func = sort_insertion;
            return;
        case 'm':
        case 'M':
            printf("using merge sort\n");
            sort_func = sort_merge;
            return;
        case 'q':
        case 'Q':
            printf("using quick sort\n");
            sort_func = sort_quick;
            return;
        default:
            show_syntax(av[0]);
            return;
    }
}

int init_array(int n) {
    int *p = a = malloc(n * sizeof(int));
    if (a == NULL) {
        return(1);
    }
    while (n--) {
        *p++ = rand();
    }
    return(0);
}

int main(int ac, char **av) {
    parse_args(ac, av);
    if (sort_func != NULL) {
        if (n == 0) {
            show_syntax(av[0]);
            return(1);
        }
        if (init_array(n)) {
            printf("error allocating array of %i random numbers\n", n);
            return(1);
        }
        clock_t start = clock(), diff;
        sort_func(a, n);
        diff = clock() - start;
        int msec = diff * 1000 / CLOCKS_PER_SEC;
        printf("ran in %d seconds %d ms\n", msec/1000, msec);
        free(a);
        return(0);
    } else {
        return(1);
    }
}
