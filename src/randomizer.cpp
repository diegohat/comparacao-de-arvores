#include "randomizer.hpp"

using namespace std;

Randomizer::Randomizer()
{
}

Randomizer::Randomizer(string fileName)
{
    // Gerando valores aleatórios
    mt19937 generator(rd());
    uniform_real_distribution<> distribution(MIN_RANGE, MAX_RANGE);
    // Abrindo arquivo
    this->fileName = fileName.append(".txt");
    fileData.open(this->fileName, ios::out);
    if (!fileData.good())
    {
        cerr << "Error opening " << this->fileName << " !" << endl;
        exit(1);
    }
    else
    {
        cout << "Creating random values..." << endl;
        // Escrevendo valores aleatórios no arquivo
        for (int i = 0; i < DATA_SIZE; i++)
        {
            if (i % 20 == 0)
                fileData << endl;
            fileData << fixed << setprecision(3) << distribution(generator) << " ";
        }
        cout << "Random values written." << endl;
    }
    fileData.close();
    cout << "File saved." << endl;
}

Randomizer::~Randomizer()
{
}