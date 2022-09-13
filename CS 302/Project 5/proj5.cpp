#include "BinarySearchTree.cpp"
#include "BinaryNode.cpp"

#include <cstdlib>

using namespace std;

int main(){
    BinarySearchTree<int> tree1;

    for(int i = 0; i < 100;i++){
        int random = rand() % 200 + 1;
        tree1.add(random);
    }

    BinaryNode<int>* root = tree1.getRoot();


    cout << "Inorder: ";
    tree1.inorder(root);
    cout << endl << "Postorder: ";
    tree1.postorder(root);
    cout << endl << "Preorder: ";
    tree1.preorder(root);

 }
