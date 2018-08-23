#include <getopt.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <vector>
#include "individual.hpp"

void
describe(Individual i) {
    std::cout << "Name: " << i.get_firstname() << " " << i.get_surname() << "\n";
    std::cout << " Sex: ";
    if ( i.get_sex() < 0 ) {
        std::cout << "female (" << i.get_sex() << ")";
    }
    else {
        std::cout << "male (" << i.get_sex() << ")";
    }
    std::cout << "Height: " << i.get_height() << "m, Weight: " << i.get_weight() << " kg" << std::endl;
}

std::string
get_random_firstname(float sex) {
    std::vector <std::string> mnames = {
        "Oliver", "George", "Harry", "Jack", "Jacob", "Noah", "Charlie", "Muhammad",
        "Thomas", "Oscar",
    };
    std::vector <std::string> fnames = {
        "Olivia", "Amelia", "Emily", "Isla", "Ava", "Jessica", "Isabella", "Lily",
        "Ella", "Mia",
    };
    if ( sex < 0.0 ) {
        return fnames[rand() % fnames.size()];
    }
    return mnames[rand() % mnames.size()];
}

std::string
get_random_surname() {
    std::vector <std::string> surnames = {
        "Smith", "Jones", "Taylor", "Brown", "Williams", "Wilson", "Johson", "Davies",
        "Robinson", "Wright", "Thompson", "Evans", "Walker", "White", "Roberts",
        "Green", "Hall", "Wood", "Jackson", "Clarke",
    };
    return surnames[rand() % surnames.size()];
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
    float tmp_s;
    for (int i = 0; i < sample_size; i++) {
        tmp_s = (float)rand() / ((float)RAND_MAX + 1) - 0.5f;
        Individual p1 { tmp_s };
        p1.set_height(get_random_height(tmp_s));
        p1.set_weight(get_random_weight(p1.get_height()));
        describe(p1);
    }
    return 0;
}
