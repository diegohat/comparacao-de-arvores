#include "bst.hpp"

using namespace std;

Bst::Bst(float data)
{
    this->data = data;
    left = right = nullptr;
}

float Bst::searchData(Bst *root, float data)
{
    if(!root)
    {
        cout << "Árvore vazia!" << endl;
        return NULL;
    }

    if(data == root->data)
        return data;
    
    if(data > root->data)
        return searchData(root->right, data);
    
    if(data < root->data)
        return searchData(root->left, data);
}

Bst* Bst::insertData(Bst *root, float data)
{
    if(!root)
        return new Bst(data);

    if(data > root->data)
        root->right = insertData(root->right, data);
    
    else if(data < root->data)
        root->left = insertData(root->left, data);
    
    return root;
}

Bst* Bst::removeData(Bst *root, float data)
{
    if(!root)
        return root;
    
    if(data > root->data)
        root->right = removeData(root->right, data);
    
    else if(data < root->data)
        root->left = removeData(root->left, data);

    else
    {
        if(!root->right)
        {
            Bst *aux = root->right;
            free(root);
            return aux;
        }

        else if(!root->left)
        {
            Bst *aux = root->left;
            free(root);
            return aux;
        }
    }
}

void Bst::inOrder(Bst *root)
{
    if(!root)
        return;
    cout << root->data << endl;
    inOrder(root->left);
    inOrder(root->right);
}