CC = g++


nodeTest: node.cpp nodeTest.cpp
	$(CC) node.cpp nodeTest.cpp -g -o ./nodeTest
