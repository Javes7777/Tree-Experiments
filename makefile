OBJS    = tree_tester.o
SOURCE	= tree_tester.cpp
OUT 	= tree_tester
CC	    = g++ 

all: $(OBJS) 

tree_tester.o: tree_tester.cpp
	@echo "Welcome to 225 Assignment 3..........\n Created by Piyush Khurana \n 301401571"
	@echo "Compiling files......................\n"
		$(CC) tree_tester.cpp -o tree_tester

clean:
		@echo "Cleaning up.........\n"
		@echo " Thank you "
		rm -f $(OUT) 
run: 
	./tree_tester

clrscr:
	clear