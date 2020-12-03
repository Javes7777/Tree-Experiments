#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include <cstdlib>
#include <fstream>
#include <time.h>	
using namespace std;

int init_size = 3;		// intial size of the trees --can be changed later	
int n = 100;		// number of operations --can be changed later	
ofstream fout1, fout2;		// fout1 for bst1 and fout2 for avl1
    // Test program

double elapsed_time( clock_t start, clock_t finish) {
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

void print_to_file(ofstream &fout, double &time, int size, int height, int ipl, bool print = 1) {
	// time is total time in milliseconds
	// n is the number operations, available globally
	double avg_depth = static_cast<double>(ipl)/size;
	fout<<n<<","<<size<<","<<height<<","<<avg_depth<<","<<(time/3*n)<<endl;

	if(print == 1) {			// for printing on console
		cout<<endl;
		cout<<"Number of operations: "<<n<<endl;
		cout<<"Size of the tree: "<< size <<endl;
		cout<<"Height of the tree: "<< height <<endl;
		cout<<" Average Node Depth: "<< avg_depth <<endl;
		cout<<"Average time for operations: "<< time/(3*n) <<endl<<endl;		// time divided by number of operations
	}
}

void do_operations(BinarySearchTree<int> &bst1, AvlTree<int> & avl1, bool print = 1) {
	// do '3n' (n insertions, n searches and n removals) number of operations on bst1 and avl1
	// next it will put these stats on the csv file,
	// the next thing is to print these values to console or not,
	int x = 101;
	int size, height, ipl;
	double t1, t2;
	clock_t start, finish;

	start = clock();
    for(int i = 0; i<n; i++ ) {
    	bst1.insert(x+i);
    }		// n insertions in trees
    for(int i = 0; i<n; i++ ) {
    	bst1.contains(x+i);
    }		// n number of searches
    size = bst1.getSize();
    height = bst1.getHeight();
    ipl = bst1.ipl();
    for(int i = 0; i<n; i++ ) {
    	bst1.remove(x+i);
    }		// n number of removals
    finish = clock();
    t1 = elapsed_time(start, finish);  // converted in seconds as well.

    print_to_file(fout1, t1, size, height, ipl );

    start.~clock_t();
    finish.~clock_t();
    start = clock();
    for(int i = 0; i<n; i++ ) {
    	avl1.insert(x+i);
    }		// n insertions in trees
    for(int i = 0; i<n; i++ ) {
    	avl1.contains(x+i);
    }		// n number of searches
    size = avl1.getSize();
    height = avl1.getHeight();
    ipl = avl1.ipl();
    for(int i = 0; i<n; i++ ) {
    	avl1.remove(x+i);
    }		// n number of removals
    finish = clock();
    t2 = elapsed_time(start, finish);

	print_to_file(fout2, t2, size, height, ipl );    // size is same so not counting again.
}

void print_initial_statistics(BinarySearchTree<int> &bst1, AvlTree<int> & avl1) {
	int size = bst1.getSize();
	cout<<endl;
	cout<<"Size of trees: "<< size <<endl;
	// this is common

	// for bst:
	cout<<"Height of BinarySearchTree: "<< bst1.getHeight() <<endl;
	cout<<"BinarySearchTree Average Node Depth: "<< bst1.ipl()/size <<endl<<endl;

	// for avl:
	cout<<"Height of AvlTree: "<< avl1.getHeight() <<endl;
	cout<<"AvlTree Average Node Depth: "<< avl1.ipl()/size <<endl<<endl;
}

int main() {

    BinarySearchTree<int> bst1;
    AvlTree<int> avl1;
    // both trees are initially empty
    // now we gonna insert same nunmber of random keys in both
    int x = 0;
    srand(time(NULL));

    for(int i=0;i<init_size;i++) {
    	// note: actual size maybe less than the given size, it is because we cannot insert the same number twice.
    	x = rand()%100 + 1;		// random number between 1 and 100.
    	bst1.insert(x);
    	avl1.insert(x);
    }

    // if you wish to see the initial trees can uncomment this section.
   	/*cout<<"Printing the binary search tree: " <<endl;
    bst1.displayTree();
	
    cout<<"Printing the AVL tree: " <<endl;
    avl1.printTree();
    */


    // now we  proceed to do operations.
    // n number operations mix of insertions removals and searches.

    //print_initial_statistics(bst1, avl1);		// to print initial stats. -- for debugging

    fout1.open("stat_bst.csv");
	fout2.open("stat_avl.csv");


    fout1<<"Num_operations,size,height,avg_node_depth,avg_time_operations"<<endl;
    fout2<<"Num_operations,size,height,avg_node_depth,avg_time_operations"<<endl;
    
    n = 10;
    do_operations(bst1, avl1);

    n = 100;
    do_operations(bst1, avl1);

    n = 500;
    do_operations(bst1, avl1);

    n = 1000;
    do_operations(bst1, avl1);

    n = 2500;
    do_operations(bst1, avl1);

    n = 5000;
    do_operations(bst1, avl1);

    n = 7500;
    do_operations(bst1, avl1);

    n = 10000;
    do_operations(bst1, avl1);

    n = 15000;
    do_operations(bst1, avl1);

    n = 20000;
    do_operations(bst1, avl1);

    fout1.close();
    fout2.close();

    return 0;
}