#include "randomizer.hpp"

using namespace std;

int main()
{
    string fileName;
    cout << "Insert File Name: " << endl;
    cin >> fileName;

    Randomizer randomData (fileName);

    return 0;
}