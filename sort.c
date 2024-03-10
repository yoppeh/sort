/**
 * @file sort.c
 * @author Warren Mann (warren@nonvol.io)
 * @brief Implementations of various sorting algorithms.
 * @version 0.1
 * @date 2024-03-10
 * 
 * @copyright Copyright (c) 2024
 */

#include <stdlib.h>
#include <string.h>


// BUBBLE SORT

void sort_bubble(int *a, int n) {
    int i, j;
    int s = 1;
    for (i = 1; i < n - 1 && s == 1; i++) {
        s = 0;
        for (j = 0; j < n - i; j++) {
            if (a[j] > a[j + 1]) {
                a[j] ^= a[j + 1];
                a[j + 1] ^= a[j];
                a[j] ^= a[j + 1];
                s = 1;
            }
        }
    }
}


// HEAP SORT

static void sift_down(int *a, int s, int e) {
    int r = s;
    while ((2 * r + 1) <= e) {
        int c = (2 * r + 1);
        int w = r;
        if (a[w] < a[c]) {
            w = c;
        }
        if (c + 1 <= e && a[w] < a[c + 1]) {
            w = c + 1;
        }
        if (w == r) {
            return;
        } else {
            a[r] ^= a[w];
            a[w] ^= a[r];
            a[r] ^= a[w];
            r = w;
        }
    }
}

static void heapify(int *a, int n) {
    int s = ((n - 1) - 1) >> 1;
    while (s >= 0) {
        sift_down(a, s, n - 1);
        s--;
    }
}

void sort_heap(int *a, int n) {  
    heapify(a, n);
    int e = n - 1;
    while (e > 0) {
        a[e] ^= a[0];
        a[0] ^= a[e];
        a[e] ^= a[0];
        e--;
        sift_down(a, 0, e);
    } 
}


// INSERTION SORT

void sort_insertion(int *a, int n) {
    for (int i = 1; i < n; i++) {
        int x = a[i];
        int j;
        for (j = i - 1; j >= 0 && a[j] > x; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = x;
    }
}


// MERGE SORT

static void merge(int *a, int s, int m, int e, int *b) {
    int i = s, j = m;
    for (int k = s; k < e; k++) {
        if (i < m && (j >= e || a[i] <= a[j])) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
    }
}

static void split(int *b, int s, int e, int *a) {
    if (e - s <= 1) {
        return;
    }
    int m = (e + s) / 2;
    split(a, s, m, b);
    split(a, m, e, b);
    merge(b, s, m, e, a);
}

static void m_sort(int *a, int *b, int n) {
    memcpy(b, a, n * sizeof(int));
    split(b, 0, n, a);
}

void sort_merge(int *a, int n) {
    int *b = malloc(n * sizeof(int));
    if (b == NULL) {
        return;
    }
    m_sort(a, b, n);
    free(b);
    b = NULL;
}


// QUICK SORT

static int partition(int *a, int l, int h) {
    int p = a[h];
    int i = l - 1;
    int t;
    for (int j = l; j < h; j++) {
        if (a[j] <= p) {
            i++;
            if (i != j) {
                a[i] ^= a[j];
                a[j] ^= a[i];
                a[i] ^= a[j];
            }
        }
    }
    i++;
    if (i != h) {
        a[i] ^= a[h];
        a[h] ^= a[i];
        a[i] ^= a[h];
    }
    return(i);
}

static void q_sort(int *a, int l, int h) {
    if (l >= h || l < 0) {
        return;
    }
    int p = partition(a, l, h);
    q_sort(a, l, p - 1);
    q_sort(a, p + 1, h);
}

void sort_quick(int *a, int n) {
    q_sort(a, 0, n - 1);
}
