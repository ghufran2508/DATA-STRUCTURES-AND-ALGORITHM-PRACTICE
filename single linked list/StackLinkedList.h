#pragma once

#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

#include"LinkList.h"

class Stack
{
	LinkList data;
public:
	Stack():data()
	{}
	Stack(const Stack& ref) :data(ref.data)
	{}
	Stack& operator=(const Stack& ref)
	{
		this->data = ref.data;
		return *this;
	}
	void push(int value)
	{
		this->data.insertAtTail(value);
	}
	int pop()
	{
		return data.RemoveAtTail();
	}
	~Stack()
	{
		//data.~LinkList();
	}
};

#endif