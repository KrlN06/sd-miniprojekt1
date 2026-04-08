//
// Created by Karol Nalepa on 08/04/2026.
//

#include "Random.h"

std::random_device Random::rd;
std::mt19937 Random::gen(Random::rd());

int Random::generateRandomInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(Random::gen);
}
