
#include <stdlib.h>
#include "teamvec.h"

struct teamvec {
    Team **teams;
    int size;
    int capacity;
};

TeamVec *tv_create(void) {
    TeamVec *tv = malloc(sizeof(TeamVec));

    if (tv == NULL) {
        return NULL;
    }

    tv->size = 0;
    tv->capacity = 4;
    tv->teams = malloc(tv->capacity * sizeof(Team *));

    if (tv->teams == NULL) {
        free(tv);
        return NULL;
    }

    return tv;
}

void tv_insert(TeamVec *tv, Team *t) {
    Team **temp;

    if (tv == NULL || t == NULL) {
        return;
    }

    if (tv->size == tv->capacity) {
        temp = realloc(tv->teams,
                       tv->capacity * 2 * sizeof(Team *));

        if (temp == NULL) {
            return;
        }

        tv->teams = temp;
        tv->capacity *= 2;
    }

    tv->teams[tv->size] = t;
    tv->size++;
}

int tv_size(TeamVec *tv) {
    if (tv == NULL) {
        return 0;
    }

    return tv->size;
}

Team *tv_get(TeamVec *tv, int i) {
    if (tv == NULL || i < 0 || i >= tv->size) {
        return NULL;
    }

    return tv->teams[i];
}

void tv_free(TeamVec *tv) {
    int i;

    if (tv == NULL) {
        return;
    }

    for (i = 0; i < tv->size; i++) {
        team_free(tv->teams[i]);
    }

    free(tv->teams);
    free(tv);
}
