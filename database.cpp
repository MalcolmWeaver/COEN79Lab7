// FILE: database.cpp
// CLASS implemented: database (see database.h for documentation)

// INVARIANT for the database ADT:
//   1. The items in the database are stored in a dynamic array, where each entry of the array includes
//      a company name, a pointer to the head of the linked list of products, and a
//      a pointer to the tail of the linked list of products
//   2. The number of slots in the array of companies is stored in member varibale aloc_slots
//   3. The number of used slots of the array of companies is stored in member varibale used_slots


#ifndef DATABASE_CPP
#define DATABASE_CPP

#include "database.h"


//#define USEDEBUG

#ifdef USEDEBUG
#define Debug( x ) std::cout << x
#else
#define Debug( x )
#endif


namespace coen79_lab7
{
    
    database::database(const size_type& initial_capacity) {
        used_slots = 0;
        aloc_slots = initial_capacity;
        company_array = new company[aloc_slots];
    }
    
    
    database::database(const database &src) {
        Debug("Copy constructor..." << std::endl);
	used_slots = src.used_slots;
	aloc_slots = src.aloc_slots;
	assert(aloc_slots >= used_slots);
	reserve(aloc_slots);
	for(int i=0; i < used_slots; ++i){
		company_array[i] = company(src.company_array[i]); // copy constructor. we dynamically allocated the lists within companies, but not the companies themselves
	}
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    database& database::operator= (const database &rhs) {
        Debug("Assignment operator..." << std::endl);
	used_slots = rhs.used_slots;
	reserve(rhs.aloc_slots); // could decrease size. sets aloc_slots
	assert(aloc_slots >= used_slots);
	
	for(int i=0; i < used_slots; ++i){
		company_array[i] = company(rhs.company_array[i]); // copy constructor. we dynamically allocated the lists within companies, but not the companies themselves
	}
	return *this;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    database::~database() {
        // COMPLETE THE IMPLEMENTATION...
    	//for(int i=0; i < used_slots; ++i){
    	//	list_clear(company_array[i].get_head());
    	//}
    	delete [] company_array;
    }
    
    
    void database::reserve(size_type new_capacity) {
        Debug("Reserve..." << std::endl);
	// remember to delete first
        if (new_capacity == aloc_slots)
            return; // The allocated memory is already the right size.
        
        if (new_capacity < used_slots)
            new_capacity = used_slots; // Canít allocate less than we are using.
        
        company  * old_company_arr = company_array; // copy of a pointer
        company_array = new company[new_capacity];
        for(int i=0; i < used_slots; ++i){
    		company_array[i] = old_company_arr[i];	
    	//	list_copy(old_company_arr[i].get_head(), company_array[i].get_head(), company_array[i].get_tail());
    	//	list_clear(old_company_arr[i].get_head()); 		
    	}
    	delete [] old_company_arr;
    	aloc_slots = new_capacity;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    bool database::insert_company(const std::string &entry) {
        
        Debug("Insert company..." << std::endl);

        assert(entry.length() > 0);
        
        size_type pos = search_company(entry);
        
        // If you find a company that is false, because there are duplicates
        if (pos != COMPANY_NOT_FOUND) {
            return false;
        }
	
	if(used_slots >= aloc_slots){
		reserve(2*aloc_slots);
	}
	
	company_array[used_slots] = company(entry);
	++used_slots;
	return true;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    bool database::insert_item(const std::string &company, const std::string &product_name, const float &price) {
        Debug("Insert item..." << std::endl);

        assert(company.length() > 0 && product_name.length() > 0);
        size_type pos = search_company(company);
        if(pos == COMPANY_NOT_FOUND){
        	return false;
        }
	
	return company_array[pos].insert(product_name, price);
        // COMPLETE THE IMPLEMENTATION...
        
    }
    
    
    bool database::erase_company(const std::string &company) {
        
        size_type company_index = search_company(company);
        if(company_index == COMPANY_NOT_FOUND){
        	return false;
        }
        for(int i = company_index; i < used_slots-1; ++i){
        	company_array[i] = company_array[i+1];
        }
        //edge case where array is exactly 1 element
        //if(used_slots == 1){
        //	used_slots
        //}
        --used_slots;
        return true;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    bool database::erase_item(const std::string& cName, const std::string& pName) {
        
        assert(cName.length() > 0 && pName.length() > 0);
	size_type c_index = search_company(cName);
	if(c_index == COMPANY_NOT_FOUND){return false;}
	return company_array[c_index].erase(pName);
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    
    database::size_type database::search_company(const std::string& company) {
        assert(company.length() > 0);
        assert(aloc_slots >= used_slots);
	for(int i = 0; i < used_slots; ++i){
		if(company_array[i].get_name() == company){return i;}// string comaprison 
	}
	return COMPANY_NOT_FOUND;
        // COMPLETE THE IMPLEMENTATION...
    }
    
    
    bool database::print_items_by_company(const std::string& cName) {
        assert(cName.length() > 0);

        size_type c_index = search_company(cName);
        
        if (c_index == COMPANY_NOT_FOUND) {
            return false;
        }
        
        std::cout << "Printing the products of " << cName << ":"<< std::endl;
        company_array[c_index].print_items();
        std::cout << std::endl;
        
        return true;
    }
    
    
    void database::print_companies() {
        
        std::cout << "Company List" << std::endl;
        for (int i = 0; i < used_slots; i++) {
            std::cout << "- " << company_array[i].get_name() << std::endl;
        }
    }
}

#endif
