CC = g++

mainTest: main.cpp database.cpp company.cpp node.cpp
	$(CC) main.cpp database.cpp company.cpp node.cpp -g -o ./mainTest

companyTest: companyTest.cpp company.cpp node.cpp
	$(CC) companyTest.cpp company.cpp node.cpp -g -o ./companyTest
	
nodeTest: node.cpp nodeTest.cpp
	$(CC) node.cpp nodeTest.cpp -g -o ./nodeTest
