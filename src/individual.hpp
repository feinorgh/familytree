#ifndef INDIVIDUAL_HPP
#define INDIVIDUAL_HPP
#include <string>

class Individual {
    float sex;         /* -1.0 = female, 1.0 = male */
    unsigned int age;  /* age in seconds */
    float height;
    float weight;
    std::string firstname;
    std::string surname;
    Individual *mother;
    Individual *father;
  public:
    Individual();
    Individual(float sex);
    float get_sex();
    unsigned int get_age();
    float get_height();
    float set_height(float h);
    float get_weight();
    float set_weight(float w);
    std::string get_firstname();
    std::string get_surname();
    Individual get_mother();
    Individual get_father();
};


#endif /* INDIVIDUAL_HPP */
