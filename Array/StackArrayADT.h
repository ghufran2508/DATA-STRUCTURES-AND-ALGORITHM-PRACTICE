#pragma once

#ifndef STACKARRAYADT_H
#define STACKARRAYADT_H

#include"ArrayADT.h"

class StackArrayADT
{
	ArrayADT data;
	int top;
public:
	StackArrayADT(): data()
	{
		top = -1;
	}
	StackArrayADT(int s) :data(s)
	{
		top = -1;
	}
	StackArrayADT(const StackArrayADT& ref):data(ref.data)
	{
		this->top = ref.top;
	}
	StackArrayADT& operator=(const StackArrayADT& ref)
	{
		data = ref.data;
		this->top = ref.top;
		return*this;
	}
	void push(int value)
	{
		if (top == data.getSize() - 1)
		{
			data.resize(data.getSize()*2);
		}

		data[++top] = value;
	}
	int pop()
	{
		return data[top--];
	}
	int Top()const
	{
		return top;
	}
	~StackArrayADT()
	{
		//data.~ArrayADT();
	}
};


#endif