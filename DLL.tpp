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

//get the data to compare
template <typename T>
T node<T>::get_data() const
{
	return data;
}
//set the previous pointer
template <typename T>
typename node<T>::node_ptr_type & node<T>::set_prev(node<T> * new_prev)
{
	previous = new_prev;
	return previous;
}

//set the next pointer
template <typename T>
typename node<T>::node_ptr_type & node<T>::set_next(node<T> * new_next)
{
	next = new_next;
	return next;
}

//return the previous pointer
template <typename T>
typename node<T>::node_ptr_type & node<T>::get_prev()
{
	return previous;
}

//return the next pointer
template <typename T>
typename node<T>::node_ptr_type & node<T>::get_next()
{
	return next;
}

/*
//compare if the current data is less than new data
template <typename T>
bool node<T>::less_than_or_equal(const T & new_data)
{
	return data <= new_data;
}
*/

//return true if the data is the same
template <typename T>
bool node<T>::find(const T & to_find)
{
	if (data == to_find)
		return true;
	else
		return false;
}

//display whats stored in the node
template <typename T>
int node<T>::display() const
{
	cout << data;
	cout << endl;
	return 1;
}


//DLL
//default constructor
template <typename T>
DLL<T>::DLL(): head(nullptr), tail(nullptr)
{
}

//copy constructor
template <typename T>
DLL<T>::DLL(const DLL<T> & src)
{
	if (!src.head)
	{
		head = nullptr;
		tail = nullptr;
		return;
	}
	copy(head, tail, src.head);
}
template <typename T>
int DLL<T>::copy(node_ptr_type & head, node_ptr_type & tail, const node_ptr_type & src)
{
	//hit nullptr
	if (!src)
	{
		head = nullptr;
		return 0;
	}
	//if theres only one item in the list
	if (!src->get_next() && !src->get_prev())
	{
		head = new node(*src);
		head->set_prev(nullptr);
		head->set_next(nullptr);
		tail = head;
		return 1;
	}
	//more than one node
	node_ptr_type hold_prev = head;
	head = new node(*src);
	head->set_prev(hold_prev);
	tail = head;
	return copy(head, tail, src->get_next());
}

//assignment operator
template <typename T>
DLL<T> & DLL<T>::operator=(const DLL<T> & src)
{
	if (this == &src)
		return *this;
	remove_all(head);
	copy(head, tail, src.head);
	return *this;
}

//destructor
template <typename T>
DLL<T>::~DLL()
{
	remove_all();
}

//insert an animal
template <typename T>
int DLL<T>::insert(const T & new_animal)
{
	//insert if the list is empty
	if (!head)
	{
		head = new node(new_animal);
		head->set_prev(nullptr);
		head->set_next(nullptr);
		tail = head;
		return 0;
	}
	//if to_add is less than the first item in the list
	if (head->get_data() > new_animal)
	{
		node_ptr_type hold = new node(new_animal);
		hold->set_prev(head->get_prev());
		hold->set_next(head);
		head->set_prev(hold);
		head = hold;
		return 1;
	}
	return insert(head, new_animal);
}
template <typename T>
int DLL<T>::insert(node_ptr_type & head, const T & to_add)
{
	//hits null, meaning its the largest
	if (!head)
	{
		head = new node(to_add);
		head->set_prev(this->tail);
		head->set_next(nullptr);
		this->tail = head;
		return 0;
	}
	//if current age is less than the new age
//	if (head->less_than_or_equal(to_add))
//	if (head->get_data() <= to_add && head->get_next()->get_data() > to_add)
	if (head->get_data() <= to_add)
	{
		//if next is not null, compare it and add if true
		if (head->get_next())
		{
			if (head->get_next()->get_data() > to_add)
			{
				node_ptr_type hold = new node(to_add);
				hold->set_next(head->get_next());
				if (head->get_next())
					head->get_next()->set_prev(hold);
				hold->set_prev(head);
				head->set_next(hold);
				if (!hold->get_next())
					this->tail = hold;
				return 1;
			}
		}
	}
	//keep going until it hits nullptr
	return insert(head->get_next(), to_add);
}

//display the animal hierarchy
template <typename T>
int DLL<T>::display() const
{
	if (!head)
		return 0;
	return display(head);
}
template <typename T>
int DLL<T>::display(const node_ptr_type & head) const
{
	if (!head)
		return 0;
	head->display();
	return 1 + display(head->get_next());
}

//find an animal to remove from the list
template <typename T>
int DLL<T>::remove(const T & find_animal)
{
	if (!head)
		return 0;
	return remove(head, find_animal);
}
template <typename T>
int DLL<T>::remove(node_ptr_type & head, const T & find_animal)
{
	//nullptr
	if (!head)
		return 0;
	//if data matches, delete and return
	if (head->find(find_animal))
	{
		node_ptr_type hold = head->get_next();
		if (hold)
			hold->set_prev(head->get_prev());
		delete head;
		head = hold;
		if (!head || !head->get_next())
			this->tail = head;
		return 1;
	}
	return remove(head->get_next(), find_animal);
}

//remove the entire list
template <typename T>
int DLL<T>::remove_all()
{
	if (!head)
		return 0;
	return remove_all(head);
}
template <typename T>
int DLL<T>::remove_all(node_ptr_type & head)
{
	if (!head)
	{
		this->tail = nullptr;
		return 0;
	}
//	node hold = head->get_next();
	node_ptr_type hold = head->get_next();
	delete head;
	head = hold;
	return 1 + remove_all(head);
}

#endif
