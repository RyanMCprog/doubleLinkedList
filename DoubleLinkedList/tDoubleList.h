#pragma once
#include <iostream>
template<typename T>
class tDoubleList
{
	struct Node
	{
	    T data;
		Node * prev;
		Node * next;

		Node() 
		{
			prev = next = nullptr;
		}

		Node(const T& val)
		{ 
			prev = next = nullptr; 
			data = val; 
		}
	};

	Node * head;
	Node * tail;

public:
	tDoubleList();
	tDoubleList(const tDoubleList &other);
	tDoubleList& operator=(const tDoubleList &rhs);
	~tDoubleList();

	void push_front(const T& val);
	void pop_front();
	void push_back(const T& val);
	void pop_back();
	void printList();

	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	void remove(const T& val);

	int sizeofList();

	bool empty() const;
	void clear();
	void resize(size_t newSize);

	class iterator
	{
		Node* cur;

	public:
		//point to head
		iterator();
		iterator(Node* startNode);

		bool operator==(const iterator& rhs) const;
		bool operator!=(const iterator& rhs) const;
		T& operator*();
		const T& operator*() const;
		//moves cur pointer
		iterator& operator++();
		iterator operator++(int n);
		iterator& operator--();
		iterator operator--(int n);
	};

	iterator begin();
	const iterator begin() const;
	iterator end();
	const iterator end() const;
};



//constructors
template<typename T>
inline tDoubleList<T>::tDoubleList()
{
	head = nullptr;
	tail = nullptr;
}

template<typename T>
inline tDoubleList<T>::tDoubleList(const tDoubleList & other)
{
	for (auto v : other)
	{
		push_back(v);
	}
}

template<typename T>
inline tDoubleList<T> & tDoubleList<T>::operator=(const tDoubleList & rhs)
{
	clear();

	for (auto v : rhs)
	{
		push_back(v);
	}

	return *this;
}

//deconstructor
template<typename T>
inline tDoubleList<T>::~tDoubleList()
{
	Node* current = head;
	while (current != 0) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}
//push and pops
template<typename T>
inline void tDoubleList<T>::push_front(const T & val)
{
	Node* new_Node = new Node();

	new_Node->data = val;

	if (head == nullptr)
	{
		head = new_Node;
		tail = new_Node;
	}
	else
	{
		
		new_Node->next = head;
		head->prev = new_Node;
		head = new_Node;
	}
	
}

template<typename T>
inline void tDoubleList<T>::pop_front()
{
	if (head != nullptr)
	{
		head = head->next;
		head->prev = nullptr;
	}
}

template<typename T>
inline void tDoubleList<T>::push_back(const T & val)
{
	Node* new_Node = new Node();

	new_Node->data = val;

	if (tail == nullptr)
	{
		tail = new_Node;
		head = new_Node;
	}
	else
	{
		new_Node->prev = tail;
		tail->next = new_Node;
		tail = new_Node;
	}
	
	
}

template<typename T>
inline void tDoubleList<T>::pop_back()
{
	if (tail != nullptr)
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
}
//prints the list in console
template<typename T>
inline void tDoubleList<T>::printList()
{
	Node* tmpCur = head;
	while (tmpCur != nullptr)
	{
		std::cout << tmpCur->data << std::endl;
		tmpCur = tmpCur->next;
	}
}
//return the value at the front of the list
template<typename T>
inline T &tDoubleList<T>::front()
{
	return head->data;
}

template<typename T>
inline const T & tDoubleList<T>::front() const
{
	return head->data;
}
//return the value at the end of the list
template<typename T>
inline T & tDoubleList<T>::back()
{
	return tail->data;
}

template<typename T>
inline const T & tDoubleList<T>::back() const
{
	return tail->data;
}

//remove all elements that match the value
template<typename T>
inline void tDoubleList<T>::remove(const T & val) //dosen't work
{
	Node* tmpCur = head;
	Node* tmpPrev = head;

	while (tmpCur != nullptr && tmpCur->data == val)
	{
		head = tmpCur->next;
		tmpCur = head;
	}
	tmpCur = head;
	while (tmpCur->next != nullptr)
	{
		if (tmpCur->data != val)
		{
			tmpPrev = tmpCur;
			tmpCur = tmpCur->next;
		}
		else
		{
			tmpPrev->next = tmpCur->next;
			tmpCur->next->prev = tmpCur->prev;
			tmpCur = tmpCur->next;
		}
	}

}
template<typename T>
inline int tDoubleList<T>::sizeofList()
{
	int count = 0;
	Node* tmpCur = head;
	while (tmpCur != nullptr)
	{
		count++;
		tmpCur = tmpCur->next;
	}
	return count;
}
//returns true if linked list is empty
template<typename T>
inline bool tDoubleList<T>::empty() const //error
{
	if (head == nullptr && tail == nullptr)
	{
		return true;
	}
	return false;
}
//clears list
template<typename T>
inline void tDoubleList<T>::clear() //dosen't work in the way wanted
{

	while (head != nullptr)
	{

		head = head->next;
	}

}

template<typename T>
inline void tDoubleList<T>::resize(size_t newSize) //error
{
	while(newSize < sizeofList())
	{
		if (tail != nullptr)
		{
			tail = tail->prev;
			tail->next = nullptr;
		}
	}

	while (newSize > sizeofList())
	{
		Node* new_Node = new Node();

		new_Node->data = 0;
		new_Node->prev = tail;
		tail->next = new_Node;
		tail = new_Node;
	}
}



//ITERATORS

template<typename T>
inline tDoubleList<T>::iterator::iterator()
{
	*cur = nullptr;
}

template<typename T>
inline tDoubleList<T>::iterator::iterator(Node * startNode)
{
	*cur = startNode;
}

template<typename T>
inline bool tDoubleList<T>::iterator::operator==(const iterator & rhs) const
{
	return cur == rhs.cur;
}

template<typename T>
inline bool tDoubleList<T>::iterator::operator!=(const iterator & rhs) const
{
	return !(cur == rhs.cur);
}

template<typename T>
inline T & tDoubleList<T>::iterator::operator*()
{
	return cur->data;
}

template<typename T>
inline const T & tDoubleList<T>::iterator::operator*() const
{
	return cur->data;
}

template<typename T>
inline typename tDoubleList<T>::iterator & tDoubleList<T>::iterator::operator++()
{
	cur = cur->next;
	return *this;
}

template<typename T>
inline typename tDoubleList<T>::iterator tDoubleList<T>::iterator::operator++(int)
{
	cur = cur->next;
	return *this;
}

template<typename T>
inline typename tDoubleList<T>::iterator & tDoubleList<T>::iterator::operator--()
{
	cur = cur->prev;
	return *this;
}

template<typename T>
inline typename tDoubleList<T>::iterator tDoubleList<T>::iterator::operator--(int)
{
	cur = cur->prev;
	return *this;
}

template<typename T>
inline typename tDoubleList<T>::iterator tDoubleList<T>::begin()
{
	return iterator(*head);
}

template<typename T>
inline const typename tDoubleList<T>::iterator tDoubleList<T>::begin() const
{
	return iterator(*head);
}

template<typename T>
inline typename tDoubleList<T>::iterator tDoubleList<T>::end()
{
	return iterator(nullptr);
}

template<typename T>
inline const typename tDoubleList<T>::iterator tDoubleList<T>::end() const
{
	return iterator(nullptr);
}
