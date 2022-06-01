#include <stdlib.h>

#include "set_int.h"

struct _node {
    int value;
    struct _node *left;
    struct _node *right;
};

typedef struct _node node;

struct _set_int {
    node *root;
};

set_int *set_int_new() {
    set_int *s = malloc(sizeof(set_int));
    s->root = NULL;
    return s;
}

void tree_delete(node *n) {
    if (n == NULL) {
        return;
    }
    tree_delete(n->right);
    tree_delete(n->left);
    free(n);
}

void set_int_delete(set_int **_s) {
    set_int *s = *_s;
    tree_delete(s->root);
    *_s = NULL;
}

int set_int_empty(set_int *s) {
    return s->root == NULL;
}

int set_int_has(set_int *s, int value) {
    node *n = s->root;

    while (n != NULL) {
        if (value == n->value) {
            return 1;
        }

        if (value < n->value) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    return 0;
}

void set_int_insert(set_int *s, int value) {
    node *p = NULL;
    node *n = s->root;

    while (n != NULL) {
        if (value == n->value) {
            return;
        }

        p = n;
        if (value < n->value) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    n = malloc(sizeof(node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    if (p != NULL) {
        if (value < p->value) {
            p->left = n;
        } else {
            p->right = n;
        }
    } else {
        s->root = n;
    }
}

void node_delete(set_int *s, node *p, node *n, node *c) {
    if (p != NULL) {
        if (n == p->left) {
            p->left = c;
        } else {
            p->right = c;
        }
    } else {
        s->root = c;
    }
    free(n);
}

void set_int_remove(set_int *s, int value) {
    node *p = NULL;
    node *n = s->root;

    while (n != NULL) {
        if (value == n->value) {
            break;
        }

        p = n;
        if (value < n->value) {
            n = n->left;
        } else {
            n = n->right;
        }
    }

    if (n != NULL) {
        if (n->left == NULL) {
            node_delete(s, p, n, n->right);
        } else {
            if (n->right != NULL) {
                node *m = n;
                p = n;
                n = n->left;
                while (n->right != NULL) {
                    p = n;
                    n = n->right;
                }
                m->value = n->value;
            }
            node_delete(s, p, n, n->left);
        }
    }
}

int is_balanced(set_int *s) {
    return 0;
}
