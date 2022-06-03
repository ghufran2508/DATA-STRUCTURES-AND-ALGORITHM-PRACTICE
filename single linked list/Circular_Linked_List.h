#pragma once

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include<iostream>

struct node
{
	int data;
	node* next;
	node(int value)
	{
		data = value;
		next = NULL;
	}
};

class CLList
{
	node* head, * tail;
public:
	CLList()
	{
		head = tail = NULL;
	}
	CLList(const CLList& ref)
	{
		if (ref.head != NULL)
		{
			head = new node(ref.head->data);
			tail = head;

			node* temp = ref.head->next;

			while (temp != ref.tail)
			{
				tail->next = new node(temp->data);
				temp = temp->next;
				tail = tail->next;
			}
			if (ref.head != ref.tail)
			{
				tail->next = new node(temp->data);
				tail = tail->next;
			}
		}
		else
		{
			head = tail = NULL;
		}
	}
	void insertAtHead(int value)
	{
		node* temp = new node(value);

		if (tail == NULL)
		{
			tail = temp;
		}
		temp->next = head;
		head = temp;
		tail->next = head;
	}
	int removeAtHead()
	{
		if (head == NULL) exit(0);

		node* temp = head;
		int value = temp->data;

		if (head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			head = head->next;
		}
		delete temp;
		return value;
	}
	void insertAtTail(int value)
	{
		node* temp = new node(value);

		if (head == NULL)
		{
			head = tail = temp;
			tail->next = temp;
		}
		else 
		{
			tail->next = temp;
			tail = tail->next;
			tail->next = head;
		}
	}
	int removeAtTail()
	{
		if (tail == NULL) exit(0);

		int value = tail->data;
		node* store = tail;

		if (head == tail)
		{
			head = tail = NULL;
		}
		else
		{
			node* temp = head;

			while (temp->next != tail)
			{
				temp = temp->next;
			}
			tail = temp;
			tail->next = head;
		}

		delete store;
		return value;
	}
	void show()
	{
		node* temp = head;

		while (temp != tail && temp != NULL)
		{
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		if(temp != NULL)
			std::cout << temp->data << " ";
	}
	~CLList()
	{
		node* temp = head;

		while (head != tail)
		{
			head = head->next;

			delete temp;
			temp = head;
		}

		delete temp;
		head = tail = NULL;
	}
};

#endif // !CIRCULAR_LINKED_LIST_H
