#include "chronos.hpp"

using namespace std;

int main()
{
    // RANDOM FILE CREATOR
    /*
    string fileName;
    cout << "Insert File Name: " << endl;
    cin >> fileName;
    Randomizer randomData(fileName);
    */

    cout << "BST TREE" << endl;
    chronos(500);
    chronos(5000);
    chronos(50000);
    chronos(500000);

    cout << "AVL TREE" << endl;
    chronosAVL(500);
    chronosAVL(5000);
    chronosAVL(50000);
    chronosAVL(500000);

    cout << "RBT TREE" << endl;
    chronosRBT(500);
    chronosRBT(5000);
    chronosRBT(50000);
    chronosRBT(500000);

    cout << "VECTOR" << endl;

    chronosVector(500);
    chronosVector(5000);
    chronosVector(50000);
    chronosVector(500000);

    cout << "MAP" << endl;

    chronosMap(500);
    chronosMap(5000);
    chronosMap(50000);
    chronosMap(500000);

    cout << "UNORDEREDMAP" << endl;

    chronosUnorderedMap(500);
    chronosUnorderedMap(5000);
    chronosUnorderedMap(50000);
    chronosUnorderedMap(500000);

    return 0;
}
