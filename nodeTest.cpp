#include <iostream>
#include <string>
#include "node.h"

using namespace coen79_lab7;
int main(){
	/*node a("NODE1", 1, NULL), b("NODE2", 2, NULL), c("NODE3", 4, NULL);
	node* a_ptr=&a, *b_ptr=&b, *c_ptr=&c;
	const std::string aName = "NODE1";
	a_ptr->setLink(b_ptr);
	b_ptr->setLink(c_ptr);
	*/
	// how do you know if the node was allocated dynamically or statically
	//node * tail_ptr = c_ptr;
	node * head, *tail;
	list_init(head, tail, "NODE1", 1); 
	//list_tail_insert(tail, "NODE4", 8);
	//list_tail_insert(tail, "NODE5", 16);
	list_print(head);
	//list_head_remove(head);
	//list_head_remove(head);
	//list_print(head);
	list_clear(head);
}

