#include <stdlib.h>

#include "set_int.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _set_int {
    node *first;
};

set_int *set_int_new() {
    set_int *s = malloc(sizeof(set_int));
    s->first = NULL;
    return s;
}

void set_int_delete(set_int **_s) {
    set_int *s = *_s;
    node *n = s->first;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(s);
    *_s = NULL;
}

int set_int_empty(set_int *s) {
    return s->first == NULL;
}

int set_int_has(set_int *s, int value) {
    for (node *n = s->first; n != NULL; n = n->next) {
        if (n->value == value) {
            return 1;
        }
    }
    return 0;
}

void set_int_insert(set_int *s, int value) {
    node *n;
    for (n = s->first; n != NULL; n = n->next) {
        if (value == n->value) {
            return;
        }
    }
    n = malloc(sizeof(node));
    n->value = value;
    n->next = s->first;
    s->first = n;
}

void set_int_remove(set_int *s, int value) {
    node *p = NULL;
    node *n = s->first;
    while (n != NULL) {
        if (value == n->value) {
            break;
        }
        p = n;
        n = n->next;
    }
    if (n == NULL) {
        return;
    }
    if (p != NULL) {
        p->next = n->next;
    } else {
        s->first = n->next;
    }
    free(n);
}
