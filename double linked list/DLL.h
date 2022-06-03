#pragma once

#ifndef DLL_H
#define DLL_H

#include<iostream>

using namespace std;

template<class T>
class DList;
template<class T>
class DNode
{
	friend DList<T>;
	T info;
public:
	DNode<T>* next;
	DNode<T>* prev;
	// Methods…
	DNode(T value)
	{
		info = value;
		next = NULL;
		prev = NULL;
	}
};
template<class T>
class DList
{
	DNode<T>* head;
	DNode<T>* tail;
	// Public member functions…
public:
	DList()
	{
		head = NULL;
		tail = NULL;
	}
	~DList()
	{
		DNode<T>* temp;

		while (head != NULL)
		{
			temp = head;
			head = head->next;

			delete temp;
		}
		head = tail = NULL;
	}
	DList(const DList& ref)
	{
		if (ref.head != NULL)
		{
			head = new DNode<T>(ref.head->info);

			DNode<T>* tempref = ref.head;
			DNode<T>* temp = head;

			tempref = tempref->next;

			while (tempref != NULL)
			{
				DNode<T>* newnode = new DNode<T>(tempref->info);
				temp->next = newnode;
				newnode->prev = temp;
				tempref = tempref->next;
				temp = temp->next;
			}
			tail = temp;
		}
		else
		{
			head = tail = NULL;
		}
	}

	void setHEad(DNode<T>* head)
	{
		this->head->prev = head;
		head->next = this->head;
		this->head = head;
	}
	void setTail(DNode<T>* Tail)
	{
		this->tail->next = Tail;
		Tail->prev = this->tail;
		this->tail = tail->next;
	}
	void insertAtHead(T value)
	{
		DNode<T>* temp = new DNode<T>(value);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}
	void insertAtTail(T value)
	{
		DNode<T>* temp = new DNode<T>(value);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}
	bool deleteAtHead()
	{
		if (head == NULL)
			return false;
		else
		{
			DNode<T>* temp = head;
			if (tail == head)
			{
				head = tail = NULL;
			}
			else
			{
				head = head->next;
				head->prev = NULL;
			}
			delete temp;
			return true;
		}
	}
	bool deleteAtTail()
	{
		if (tail == NULL)
			return false;
		else
		{
			DNode<T>* temp = tail;
			if (tail == head)
			{
				head = tail = NULL;
			}
			else
			{
				tail = tail->prev;
				tail->next = NULL;
			}
			delete temp;
			return true;
		}
	}
	void printList()
	{
		DNode<T>* temp = head;

		while (temp != NULL)
		{
			cout << temp->info << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	DNode<T>* getNode(int n)
	{
		DNode<T>* temp = head;

		for (int i = 0; i < n; i++)
		{
			if (temp->next == NULL)
				break;
			temp = temp->next;
		}
		return temp;
	}
	DNode<T>* search(T key)
	{
		DNode<T>* temp = head;

		while(temp->info != key && temp != NULL)
		{
			temp = temp->next;
		}
		return temp;
	}
	bool insertAfter(T value, T newvalue)
	{
		DNode<T>* temp = search(value);

		if (temp == NULL)
			return false;
		if (temp == tail)
		{
			 insertAtTail(newvalue);
		}
		else
		{
			DNode<T>* newtemp = new DNode<T>(newvalue);

			newtemp->prev = temp;
			newtemp->next = temp->next;
			temp->next->prev = newtemp;
			temp->next = newtemp;
		}
		return true;
	}
	bool deleteAfter(T value)
	{
		DNode<T>* temp = search(value);

		if (temp == NULL)
			return false;
		if (temp == head)
		{
			return deleteAtHead();
		}
		else if (temp == tail)
		{
			return deleteAtTail();
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		return true;
	}
	int getLength()
	{
		DNode<T>* temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
};

#endif // !DLL_H
