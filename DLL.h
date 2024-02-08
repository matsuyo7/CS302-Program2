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
		typedef unique_ptr <myTYPE> node_ptr_type;	//pointer type
		node();						//default constructor
		node(const node<T> & src);			//copy constructor
		node_ptr_type & get_prev();			//get the previous pointer
		node_ptr_type & get_next();			//get the next pointer
		int display() const;				//display whats stored in the node

	private:
		T data;
		node_ptr_type prev;
		node_ptr_type next;
};


template <typename T>
class DLL
{
	public:
		typedef node<T> node_type;
		typedef node_type * node_ptr;
		DLL();						//default constructor
		DLL(const DLL<T> & src);			//copy constructor
		DLL<T> & operator=(const DLL<T> & src);		//assignment operator
		int insert(const T & new_animal);		//insert an animal
		int display() const;				//display the animal hierarchy
	
	private:
		node_ptr head;
		int copy(node_ptr & dest, const node_ptr & src);
		int insert(node_ptr & head, const T & data);
		int display(const node_ptr & head) const;
};
