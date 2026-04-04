#include <cstdlib>
#include <ctime>

#include "Benchmark.h"

int main() {
    srand(time(nullptr));

    Benchmark benchmark;
    benchmark.run();

    return 0;
}