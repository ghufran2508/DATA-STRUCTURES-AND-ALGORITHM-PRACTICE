#pragma once

#ifndef XDLINKEDLIST_H
#define XDLINKEDLIST_H

#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node* npx;
	//Code complexity f(x) = 1+1 =2
	Node(int value)
	{
		data = value;	//1
		npx = NULL;		//1
	}
};
class XDLinkList
{
	Node* head, * tail;
public:
	XDLinkList();

	void print();

	XDLinkList(const XDLinkList& ref);
	void insertAtHead(int);
	void insertAtTail(int);
	int RemoveAtHead(void);
	int RemoveAtTail(void);
	void insertAtIndex(int index, int val);
	int removeAtIndex(int index);
	void insertBefore(int index, int val);
	int removeBefore(int index);
	void insertAfter(int index, int val);
	int removeAfter(int index);
	int getIndex(int value);
	int& operator[](int index);
	XDLinkList& operator=(const XDLinkList& ref);
	bool isEmpty();
	~XDLinkList();
};


#endif // !XDLINKEDLIST_H
