//Molina Nhoung
//CS302
//2/7/24
//
//Program 2
//This file will be the skeleton class for the node to store the animals data
//and the DLL class that will store the nodes in a list. Each node will have
//information from all the classes and will be a template class so that
//its type is not defined, making it usable for all animal types

#include "animals.h"

template <typename T>
class node
{
	public:
	//	typedef unique_ptr <myTYPE> node_ptr_type;	//pointer type
		typedef node<T> * node_ptr_type;		//pointer type
		node();						//default constructor
		node(const T & new_animal);			//initialization list
		node(const node<T> & src);			//copy constructor
		~node();					//destructor
		node_ptr_type & set_prev(node<T> * new_prev);	//set the previous pointer
		node_ptr_type & set_next(node<T> * new_next);			//set the next pointer
		node_ptr_type & get_prev();			//get the previous pointer
		node_ptr_type & get_next();			//get the next pointer
		int display() const;				//display whats stored in the node

	private:
		T data;
		node_ptr_type previous;
		node_ptr_type next;
};


template <typename T>
class DLL
{
	public:
		typedef node<T> * node_ptr_type;		//pointer type
	//	typedef node_type * node_ptr;
		DLL();						//default constructor
		DLL(const DLL<T> & src);			//copy constructor
		DLL<T> & operator=(const DLL<T> & src);		//assignment operator
		~DLL();						//destructor
		int insert(const T & new_animal);		//insert an animal
		int display() const;				//display the animal hierarchy
		int remove(const T & find_animal);		//find an animal to remove from the list
		int remove_all();				//remove the entire list
	
	private:
		node_ptr_type head;
		node_ptr_type tail;
		int copy(node_ptr_type & dest, const node_ptr_type & src);
		int insert(node_ptr_type & head, const T & data);
		int display(const node_ptr_type & head) const;
		int remove(node_ptr_type & head);
		int remove_all(node_ptr_type & head);
};
