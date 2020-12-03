#copied now, need to be changed

OBJS    = BSTtest.o BSTtest2.o BSTtestCL.o BSTtestDD.o BSTtestCD.o
SOURCE	= BSTtest.cpp BSTtest2.cpp BSTtestCL.cpp BSTtestDD.cpp BSTtestCD.cpp
#HEADER  = BinarySearchTree.h

CC	    = g++ 

all: $(OBJS)

BSTtest.o: 
		$(CC) -o BSTtest BSTtest.cpp  

BSTtest2.o: 
		$(CC) -o BSTtest2 BSTtest2.cpp  

BSTtestCL.o: 
		$(CC) -o BSTtestCL BSTtestCL.cpp  

BSTtestCD.o: 
		$(CC) -o BSTtestCD BSTtestCD.cpp  

BSTtestDD.o: 
		$(CC) -o BSTtestDD BSTtestDD.cpp  		


clean:
		rm -f $(OBJS) $(OUT)

