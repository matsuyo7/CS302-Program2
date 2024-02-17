//Molina Nhoung
//CS302
//2/9/24
//
//Program 2
//This file will implement the DLL functions from the DLL header file. It will keep track of one
//hierarchy at a time, such as the user wanting to keep track of pets, then the DLL will only
//hold Pets until the user quits. The functions will use a unique_ptr for the template class.

#ifndef DLL_TPP
#define DLL_TPP

//NODE
//default constructor
template <typename T>
node<T>::node(): previous(nullptr), next(nullptr)
{
}

//initialization list
template <typename T>
node<T>::node(const T & new_animal): data(new_animal), previous(nullptr), next(nullptr)
{
}

//copy constructor
template <typename T>
node<T>::node(const node<T> & src): data(src), previous(nullptr), next(nullptr)
{
}

//destructor
template <typename T>
node<T>::~node()
{
}

//set the previous pointer
template <typename T>
node<T>::node_ptr_type & set_prev(node<T> * new_prev)
{
	previous = new_prev;
	return 1;
}

//set the next pointer
template <typename T>
node<T>::node_ptr_type & set_next(node<T> * new_next)
{
	next = new_next;
	return 1;
}

//return the previous pointer
template <typename T>
node<T>::node_ptr_type & get_prev()
{
	return previous;
}

//return the next pointer
template <typename T>
node<T>::node_ptr_type & get_next()
{
	return next;
}

//display whats stored in the node
template <typename T>
int node<T>::display() const
{
	cout << data;
}


//DLL
//default constructor
template <typename T>
DLL::DLL(): head(nullptr), tail(nullptr)
{
}

//copy constructor
template <typename T>
DLL::DLL(const DLL<T> & src)
{
	copy(head, src.head);
}
template <typename T>
int DLL::copy(node_ptr_type & dest, const node_ptr_type & src)
{
	if (!src)
	{
		dest = nullptr;
		return 0;
	}
	dest = new node(*src);

}

//assignment operator
template <typename T>
DLL<T> & DLL::operator=(const DLL<T> & src)
{
}

//destructor
template <typename T>
DLL::~DLL()
{
}

//insert an animal
template <typename T>
int DLL::insert(const T & new_animal)
{
}
template <typename T>
int DLL::insert(node_ptr_type & head, const T & data)
{
}

//display the animal hierarchy
template <typename T>
int DLL::display() const
{
}
template <typename T>
int DLL::display(const node_ptr_type & head) const
{
}

//find an animal to remove from the list
template <typename T>
int DLL::remove(const T & find_animal)
{
}
template <typename T>
int DLL::remove(node_ptr_type & head)
{
}

//remove the entire list
template <typename T>
int DLL::remove_all()
{
}
template <typename T>
int DLL::remove_all(node_ptr_type & head)
{
}

#endif
