#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float sex;          /* -1.0 = female, 1.0 = male */
    unsigned int age;   /* seconds */
    float height;       /* metres */
    float weight;       /* kilograms */
    char *firstname;
    char *surname;
    struct individual *mother;
    struct individual *father;
} individual;

void
describe(individual i) {
    printf("Name: %s %s\n", i.firstname, i.surname);
    printf(" Sex: ");
    if ( i.sex < 0 ) {
        printf("female");
    }
    else {
        printf("male");
    }
    printf("\nHeight: %0.2f m, Weight: %0.2f kg", i.height, i.weight);
    printf("\n\n");
}

float
get_random_height() {
    return 0.8f + (float)rand() / ((float)RAND_MAX + 1) * 1.2f;
}

float
get_random_weight() {
    return 40.0 + (float)rand() / ((float)RAND_MAX + 1) * 40.0;
}

int
main(int argc, char *argv[])
{
    srand(time(NULL));
    individual Adam = {
        .sex = 1.0, .firstname = "Adam", .surname = "Kennedy",
        .height = get_random_height(),
        .weight = get_random_weight(),
    };
    individual Eve = { .sex = -1.0, .firstname = "Eve", .surname = "Johnson",
                       .height = get_random_height(),
                       .weight = get_random_weight(),
                     };
    int generations = 1000;
    int current_generation = 0;
    while ( current_generation < generations ) {
        current_generation++;
    }
    describe(Adam);
    describe(Eve);
    return 0;
}
