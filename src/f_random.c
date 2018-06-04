#include "f_random.h"

void *
get_random(void *p, size_t size) {
    FILE *f;
    f = fopen("/dev/urandom", "r");
    fread(&p, size, 1, f);
    fclose(f);
    return p;
}

int
rand_i(int min, int max) {
    unsigned int n;
    get_random(&n, sizeof n);
    printf("%u\n", n);
    return n;
}

float
rand_f(float min, float max) {
    float n;
    get_random(&n, sizeof n);
    return n;
}

float
rand_n() {
    float n;
    get_random(&n, sizeof n);
    return n;
}
