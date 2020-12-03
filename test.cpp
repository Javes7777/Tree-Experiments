#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

    // Test program
int main() {

    BinarySearchTree<int> bst1;
    bst1.insert(10);
	bst1.insert(5);
	bst1.insert(15);
	bst1.insert(3);
	bst1.insert(7);
	bst1.insert(13);
	bst1.insert(18);
	bst1.insert(4);
	bst1.insert(2);
	bst1.insert(20);
	bst1.insert(22);
	bst1.insert(12);
	bst1.insert(45);
	bst1.insert(34);

    cout<<"Printing the tree: " <<endl;
    bst1.displayTree();

    cout<<"Internal Path Length: " << bst1.IPL()<<endl;
    //cout<<"Height: " << bst1.getHeight()<<endl;
}