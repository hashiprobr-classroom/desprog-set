#include <stdlib.h>

#include "set_int.h"

struct _set_int {
};

set_int *set_int_new() {
    set_int *s = malloc(sizeof(set_int));
    return s;
}

void set_int_delete(set_int **_s) {
    set_int *s = *_s;
    free(s);
    *_s = NULL;
}

int set_int_empty(set_int *s) {
    return 0;
}

int set_int_has(set_int *s, int value) {
    return 0;
}

void set_int_insert(set_int *s, int value) {
}

void set_int_remove(set_int *s, int value) {
}
