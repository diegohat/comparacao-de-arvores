#include <iostream>

class Bst
{
private:
    float data;
    Bst *left, *right;

public:
    Bst() : data(0.0), left(nullptr), right(nullptr) {};
    Bst(float);
    ~Bst() {};

    float searchData(Bst*, float);
    Bst* insertData(Bst* , float);
    Bst* removeData(Bst* , float);
    void inOrder(Bst*);
};
