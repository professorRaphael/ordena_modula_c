#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

static void copy_arr(int *dst, const int *src, size_t n) {
    for (size_t i = 0; i < n; ++i) dst[i] = src[i];
}

/* mede tempo em milissegundos:
   - copia base -> buf
   - chama o sort
   - retorna o tempo gasto */
static double medir_tempo(void (*sort_fn)(int*, size_t),
                          int *buf, const int *base, size_t n) {
    copy_arr(buf, base, n);
    clock_t ini = clock();
    sort_fn(buf, n);
    clock_t fim = clock();
    return 1000.0 * (double)(fim - ini) / CLOCKS_PER_SEC;
}

/* só pra mostrar alguns elementos (não imprime tudo se n for grande) */
static void print_prefix(const char *label, const int *v, size_t n) {
    printf("%s", label);
    size_t limite = n < 10 ? n : 10;
    for (size_t i = 0; i < limite; ++i) {
        printf("%s%d", (i ? " " : ""), v[i]);
    }
    if (n > limite) printf(" ...");
    puts("");
}

int main(void) {
    /* use um n maior pra ver diferença de tempo;
       pode ir ajustando (10000, 50000, 100000, etc.) */
    const size_t n = 20000;

    int *base = malloc(n * sizeof *base);
    int *a    = malloc(n * sizeof *a);
    int *b    = malloc(n * sizeof *b);
    int *c    = malloc(n * sizeof *c);
    int *d    = malloc(n * sizeof *d);

    if (!base || !a || !b || !c || !d) {
        fprintf(stderr, "Erro de memoria\n");
        free(base); free(a); free(b); free(c); free(d);
        return 1;
    }

    /* gera dados aleatórios para o teste */
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < n; ++i) {
        base[i] = rand() % 100000;  // valores entre 0 e 99999
    }

    printf("n = %zu elementos\n", n);

    double t_ins = medir_tempo(insertion_sort, a, base, n);
    double t_quick = medir_tempo(quick_sort, b, base, n);
    double t_merge = medir_tempo(merge_sort, c, base, n);
    double t_heap  = medir_tempo(heap_sort,  d, base, n);

    /* mostra só o começo de cada vetor ordenado, para conferir */
    print_prefix("Insertion (prefixo ordenado): ", a, n);
    print_prefix("Quick     (prefixo ordenado): ", b, n);
    print_prefix("Merge     (prefixo ordenado): ", c, n);
    print_prefix("Heap      (prefixo ordenado): ", d, n);

    puts("");
    puts("Tempos aproximados:");
    printf("Insertion sort : %8.3f ms  (complexidade teórica: O(n^2))\n", t_ins);
    printf("Quick sort     : %8.3f ms  (complexidade teórica: O(n log n) em média, O(n^2) pior caso)\n", t_quick);
    printf("Merge sort     : %8.3f ms  (complexidade teórica: O(n log n))\n", t_merge);
    printf("Heap sort      : %8.3f ms  (complexidade teórica: O(n log n))\n", t_heap);

    free(base); free(a); free(b); free(c); free(d);
    return 0;
}
