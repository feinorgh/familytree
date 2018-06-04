#ifndef RANDOM_H
#define RANDOM_H
#include <stdio.h>

void *
get_random(void *, size_t size);

int
rand_i(int min, int max);

float
rand_f(float min, float max);

float
rand_n();

#endif /* RANDOM_H */
