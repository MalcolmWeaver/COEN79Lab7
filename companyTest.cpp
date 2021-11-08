#include <iostream>
#include "company.h"
#include "node.h"

using namespace coen79_lab7;

int main(){
	company c1, c2("Google");
	company c3(c2);
	c1 = c3;
	c3.insert("Search", 350);
	c3.insert("Calendar", 300);
	c3.insert("gmail", 250);
	c3.insert("gmail", 2504);
	c3.erase("Calendar");
	c2 = c3;
	std::cout << "List named " << c2.get_name() << ": ";
	list_print(c2.get_head());
}
