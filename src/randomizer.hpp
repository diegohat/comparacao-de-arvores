#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>

#define MIN_RANGE 0.0
#define MAX_RANGE 1000.0
#define DATA_SIZE 10000

class Randomizer
{
private:
    std::random_device rd;
    std::string fileName;
    std::ofstream fileData;

public:
    Randomizer(std::string fileName);
    Randomizer();
    ~Randomizer();
};
