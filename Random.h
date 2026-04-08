//
// Created by Karol Nalepa on 08/04/2026.
//

#ifndef PROJEKT_1_RANDOM_H
#define PROJEKT_1_RANDOM_H
#include <random>


class Random {



public:
    static int generateRandomInt(int min, int max);

private:

    static std::random_device rd;
    static std::mt19937 gen;

};

#endif //PROJEKT_1_RANDOM_H
