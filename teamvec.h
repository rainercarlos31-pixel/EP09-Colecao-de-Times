
#ifndef TEAMVEC_H
#define TEAMVEC_H

#include "team.h"

typedef struct teamvec TeamVec;

TeamVec *tv_create(void);

void tv_insert(TeamVec *tv, Team *t);

int tv_size(TeamVec *tv);

Team *tv_get(TeamVec *tv, int i);

void tv_free(TeamVec *tv);

#endif
