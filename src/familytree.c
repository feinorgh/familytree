#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH(array) ( sizeof array / sizeof array[0] )

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

char *
get_random_firstname(float sex) {
    char *mnames[] = {
        "Oliver", "George", "Harry", "Jack", "Jacob", "Noah", "Charlie", "Muhammad",
        "Thomas", "Oscar",
    };
    char *fnames[] = {
        "Olivia", "Amelia", "Emily", "Isla", "Ava", "Jessica", "Isabella", "Lily",
        "Ella", "Mia",
    };
    char **names;
    unsigned short int len = 0;
    if ( sex < 1.0 ) {
        names = fnames;
        len   = LENGTH(fnames);
    }
    else {
        names = mnames;
        len   = LENGTH(mnames);
    }
    return names[(short int)(rand() / ((float)RAND_MAX + 1) * len)];
}

char *
get_random_surname() {
    char *surnames[] = {
        "Smith", "Jones", "Taylor", "Brown", "Williams", "Wilson", "Johson", "Davies",
        "Robinson", "Wright", "Thompson", "Evans", "Walker", "White", "Roberts",
        "Green", "Hall", "Wood", "Jackson", "Clarke",
    };
    return surnames[(int)(rand() / ((float)RAND_MAX + 1) * LENGTH(surnames))];
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
        .sex = 1.0, .firstname = get_random_firstname(1.0f),
        .surname = get_random_surname(),
        .height = get_random_height(),
        .weight = get_random_weight(),
    };
    individual Eve = {
        .sex = -1.0, .firstname = get_random_firstname(-1.0f),
        .surname = get_random_surname(),
        .height = get_random_height(),
        .weight = get_random_weight(),
    };
    /*
     * int generations = 1000;
    int current_generation = 0;
    while ( current_generation < generations ) {
        current_generation++;
    }
    */
    describe(Adam);
    describe(Eve);
    return 0;
}
