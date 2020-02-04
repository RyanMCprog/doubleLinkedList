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

		//constructors
		Node() 
		{
			prev = next = nullptr;
		}

		Node(const T& val)
		{ 
			prev = next = nullptr; 
			data = val; 
		}

		Node(const T& val, Node * _next, Node * _prev)
		{
			prev = _prev;
			next = _next;
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
	head = new Node();
	tail = new Node();
	head->next = tail;
	tail->prev = head;
}
//copy constructors
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
//pushs to the front of the linked list and changes it so the head and the node in front it are pointing to the new node
template<typename T>
inline void tDoubleList<T>::push_front(const T & val)
{
	Node* new_Node = new Node(val,head->next,head);



	head->next = new_Node;
	new_Node->next->prev = new_Node;


	
	
}
//removes the node in the front and changes so the head and the node in front of the removed node are pointing at eachother
template<typename T>
inline void tDoubleList<T>::pop_front()
{
	head->next = head->next->next;
	head->next->prev = head;

}
//pushs to the back of the linked list and changes it so the tail and the node behind it are pointing to the new node
template<typename T>
inline void tDoubleList<T>::push_back(const T & val)
{
	Node* new_Node = new Node(val,tail,tail->prev);

	tail->prev = new_Node;
	new_Node->prev->next = new_Node;

	
	
	
}
//removes the node in the back and changes so the tail and the node behind the removed node are pointing at eachother
template<typename T>
inline void tDoubleList<T>::pop_back()
{
	tail->prev = tail->prev->prev;
	tail->prev->next = tail;
	
}
//prints the list in console
template<typename T>
inline void tDoubleList<T>::printList()
{
	Node* tmpCur = head->next;
	std::cout << "XXXXX\n";
	while (tmpCur != nullptr)
	{
		if (tmpCur->next != nullptr)
		{
			std::cout << tmpCur->data << std::endl;
		}
		tmpCur = tmpCur->next;
	}
}
//return the value at the front of the list
template<typename T>
inline T &tDoubleList<T>::front()
{
	return head->next->data;
}

template<typename T>
inline const T & tDoubleList<T>::front() const
{
	return head->next->data;
}
//return the value at the end of the list
template<typename T>
inline T & tDoubleList<T>::back()
{
	return tail->prev->data;
}

template<typename T>
inline const T & tDoubleList<T>::back() const
{
	return tail->prev->data;
}

//remove all elements that match the value
template<typename T>
inline void tDoubleList<T>::remove(const T & val) 
{
	Node* tmpCur = head->next;
	Node* tmpPrev = head->next;

	while (head->next != tail && head->next->data == val)
	{
		head->next = head->next->next;
		head->next->prev = head;
	}
	tmpCur = head->next;
	while (tmpCur != tail)
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
	Node* tmpCur = head->next;
	while (tmpCur != tail)
	{
		count++;
		tmpCur = tmpCur->next;
	}
	return count;
}
//returns true if linked list is empty
template<typename T>
inline bool tDoubleList<T>::empty() const 
{
	if (head->next == tail)
	{
		return true;
	}
	return false;
}
//clears list
template<typename T>
inline void tDoubleList<T>::clear() 
{

	while (head->next != tail)
	{
		head->next = head->next->next;
		head->next->prev = head;
	}

}
//changes the size of the linked list
template<typename T>
inline void tDoubleList<T>::resize(size_t newSize) 
{
	while(newSize < sizeofList())
	{
		if (tail->prev != head)
		{
			tail->prev = tail->prev->prev;
			tail->prev->next = tail;
		}
	}

	while (newSize > sizeofList())
	{
		Node* new_Node = new Node(0, tail, tail->prev);

		tail->prev = new_Node;
		new_Node->prev->next = new_Node;
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
