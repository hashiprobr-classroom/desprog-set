#include <stdlib.h>

#include "set_int.h"

struct _set_int {
    int capacity;
    int *data;
    int size;
};

set_int *set_int_new(int capacity) {
    set_int *s = malloc(sizeof(set_int));
    s->capacity = capacity;
    s->data = malloc(capacity * sizeof(int));
    s->size = 0;
    return s;
}

void set_int_delete(set_int **_s) {
    set_int *s = *_s;
    free(s->data);
    free(s);
    *_s = NULL;
}

int set_int_empty(set_int *s) {
    return s->size == 0;
}

int set_int_full(set_int *s) {
    return s->size == s->capacity;
}

int set_int_has(set_int *s, int value) {
    return 0;
}

void set_int_insert(set_int *s, int value) {
}

void set_int_remove(set_int *s, int value) {
}
