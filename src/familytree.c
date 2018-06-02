#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "f_random.h"

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
        printf("female (%f)", i.sex);
    }
    else {
        printf("male (%f)", i.sex);
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
    if ( sex < 0.0 ) {
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
get_random_height(float sex) {
    float average_height = 1.778f;
    if ( sex < 0.0 ) {
        average_height /= 1.08;
    }
    return average_height + ((float)rand() / ((float)RAND_MAX + 1) - 0.5) * 0.65;
}

float
get_random_weight(float height) {
    float bmi = 15.0 + (float)rand() / ((float)RAND_MAX + 1) * 25.0;
    return bmi * height * height;
}

int
main(int argc, char *argv[])
{
    int sample_size = 1;
    int c;
    while (1) {
        int option_index = 0;
        static struct option long_options[] = {
            {"help",    no_argument,       0, 0 },
            {"samples", required_argument, 0, 0},
            {0,      0,                    0, 0 },
        };

        c = getopt_long(argc, argv, "hs:", long_options, &option_index);
        if ( c == -1 ) {
            break;
        }
        switch (c) {
            case 'h':
                printf("Request for help\n");
                break;

            case 's':
                sample_size = atoi(optarg);
                break;

            case '?':
                break;

            default:
                printf("?? getopt returned character code 0%o ??\n", c);
        }
    }

    srand(time(NULL));
    float tmp_h, tmp_s;
    float real_average_height = 0.0;
    for (int i = 0; i < sample_size; i++) {
        tmp_s = (float)rand() / ((float)RAND_MAX + 1) - 0.5f;
        tmp_h = get_random_height(tmp_s);
        individual tmp_i = {
            .sex = tmp_s,
            .firstname = get_random_firstname(tmp_s),
            .surname = get_random_surname(),
            .height = tmp_h,
            .weight = get_random_weight(tmp_h),
        };
        describe(tmp_i);
        if ( real_average_height == 0 ) {
            real_average_height = tmp_i.height;
        }
        else {
            real_average_height = (tmp_i.height + real_average_height) / 2.0;
        }
    }
    printf("Average height: %0.2f m\n", real_average_height);
    unsigned int n;
    get_random(&n, sizeof n);
    printf("%u\n", n);
    return 0;
}
