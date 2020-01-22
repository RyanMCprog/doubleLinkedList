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

	T& front();
	const T& front() const;
	T& tail(Node* cur);

	void remove(Node** head_ref, const T& val);

	bool empty(Node** head_ref) const;
	void clear();
	void resize(size_t newSize);
};

template<typename T>
inline tDoubleList<T>::tDoubleList()
{
	Node* head = nullptr;
	head = new Node();
}

template<typename T>
inline tDoubleList<T>::tDoubleList(const tDoubleList & other)
{
	Node* tmpHead = new Node();
	

	
}

//template<typename T>
//inline tDoubleList & tDoubleList<T>::operator=(const tDoubleList & rhs)
//{
//	// TODO: insert return statement here
//}

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

template<typename T>
inline void tDoubleList<T>::push_front(const T & val)
{
	Node* new_Node = new Node();

	new_Node->data = val;
	new_Node->next = *head;
	*head->prev = new_Node;
	*head = new_Node;
}

template<typename T>
inline void tDoubleList<T>::pop_front()
{
	if (*head != nullptr)
	{
		*head = *head->next;
		*head->prev = nullptr;
	}
}

template<typename T>
inline void tDoubleList<T>::push_back(const T & val)
{
	Node* new_Node = new Node();

	new_Node->data = val;
	//new_Node->prev = *tail_ref;
	new_Node->prev = tail;
	tail->next = new_Node;
	tail = new_Node;

	//*tail_ref->next = new_Node;
	//*tail_ref = new_Node;
}

template<typename T>
inline void tDoubleList<T>::pop_back()
{
	if (*tail != nullptr)
	{
		*tail = *tail_ref->prev;
		*tail->next = nullptr;
	}
}

template<typename T>
inline T &tDoubleList<T>::front()
{
	return head->data;
}

template<typename T>
inline const T & tDoubleList<T>::front() const
{
	// TODO: insert return statement here
}

template<typename T>
inline T & tDoubleList<T>::tail(Node * cur)
{
	while (cur != nullptr && cur->next != nullptr)
	{
		cur = cur->next;
	}
	return cur;
}

template<typename T>
inline void tDoubleList<T>::remove(Node** head_ref, const T & val)
{
	Node* tmpCur = *head_ref;
	Node* tmpPrev = *head_ref;
	if (temp != nullptr && temp->data == val)
	{
		*head_ref = tmpCur->next;
	}

	while (tmpCur->next != nullptr)
	{
		if (tmpCur->data != val)
		{
			tmpPrev = tmpCur;
			tmpCur = tmpPrev->next;
		}
		else
		{
			tmpPrev->next = tmpCur->next;
		}
	}

}

template<typename T>
inline bool tDoubleList<T>::empty(Node** head_ref) const
{
	if (*head_ref == nullptr)
	{
		return true;
	}
	return false;
}

template<typename T>
inline void tDoubleList<T>::clear()
{

}


