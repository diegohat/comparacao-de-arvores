#include "randomizer.hpp"
#include "bst.hpp"

using namespace std;

int main()
{
/*     string fileName;
    cout << "Insert File Name: " << endl;
    cin >> fileName;

    Randomizer randomData(fileName);
 */
    Bst t, *root = nullptr;
    root = t.insertData(root, 77);
    float values[5] = {15, 23, 6, 44, 31};

    for (int i = 0; i < 5; i++)
    {
        t.insertData(root, values[i]);
    }

    t.inOrder(root);

    return 0;
}