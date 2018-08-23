#include "individual.hpp"

Individual::Individual() {
}

Individual::Individual(float sex) {
    this->sex = sex;
}

std::string Individual::get_firstname () {
    return firstname;
}

std::string Individual::get_surname () {
    return surname;
}

float Individual::get_sex () {
    return sex;
}

unsigned int Individual::get_age() {
    return age;
}

float Individual::get_height() {
    return height;
}

float Individual::set_height(float h) {
    return this->height = h;
}

float Individual::get_weight() {
    return weight;
}

float Individual::set_weight(float w) {
    return this->weight = w;
}

Individual Individual::get_mother() {
    return *mother;
}

Individual Individual::get_father() {
    return *father;
}
