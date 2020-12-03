#include <iostream>
#include "AvlTree.h"
using namespace std;

    // Test program
int main() {

    AvlTree<int> avl1;
    avl1.insert(10);
	avl1.insert(5);
	avl1.insert(15);
	avl1.insert(3);
	avl1.insert(7);
	avl1.insert(13);
	avl1.insert(18);
	avl1.insert(4);
	avl1.insert(2);
	avl1.insert(20);
	avl1.insert(30);
	avl1.insert(74);
	avl1.insert(45);
	avl1.insert(23);
	avl1.insert(56);
	avl1.insert(78);
	avl1.insert(67);

    cout<<"Printing the Avl tree: " <<endl;
    avl1.printTree();

    cout<<"Internal Path Length: " << avl1.ipl()<<endl;
    cout<<"size: " << avl1.getSize()<<endl;
}