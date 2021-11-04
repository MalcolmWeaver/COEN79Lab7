#include <iostream>
#include <string>
#include "node.h"

using namespace coen79_lab7;
int main(){
	node *a, *b, *c;
	const std::string aName = "NODE1";
	a->setName(aName);
	a->setPrice(1);
	a->setLink(b);
	b->setName("NODE2");
	b->setPrice(2);
	b->setLink(c);
	c->setName("NODE3");
	c->setPrice(4);
	std::cout << a;
}

