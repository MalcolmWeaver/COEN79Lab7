CC = g++

companyTest: companyTest.cpp company.cpp node.cpp
	$(CC) companyTest.cpp company.cpp node.cpp -g -o ./companyTest
	
nodeTest: node.cpp nodeTest.cpp
	$(CC) node.cpp nodeTest.cpp -g -o ./nodeTest
