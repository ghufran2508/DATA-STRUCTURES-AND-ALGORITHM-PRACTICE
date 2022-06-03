#pragma once
#ifndef STACK_POINT_H
#define STACK_POINT_H

#include<iostream>

class point
{
	int x;
	int y;
public:
	point* next;
	point(int xx, int yy)
	{
		x = xx;
		y = yy;
		next = NULL;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
};

class stack
{
	point* traversed;
public:
	stack()
	{
		traversed = NULL;
	}
	stack(const stack& ref)
	{
		if (ref.traversed != NULL)
		{
			traversed = new point(ref.traversed->getx(), ref.traversed->gety());

			point* temp = traversed;
			point* temp_ref = ref.traversed->next;

			while (temp_ref != NULL)
			{
				temp->next = new point(temp_ref->getx(), temp_ref->gety());
				temp = temp->next;
				temp_ref = temp_ref->next;
			}
		}
		else 
			traversed = NULL;
	}
	void push(int x, int y)
	{
		point* temp = new point(x, y);
		if (traversed == NULL)
			traversed = temp;
		else
		{
			temp->next = traversed;
			traversed = temp;
		}
	}
	bool isEmpty()
	{
		return (traversed == NULL);
	}
	point* pop()
	{
		if (!isEmpty())
		{
			point* temp = traversed;
			traversed = traversed->next;
			return temp;
		}
		else
			exit(0);
	}
	stack& operator=(const stack& ref)
	{
		if (ref.traversed != NULL)
		{
			traversed = new point(ref.traversed->getx(), ref.traversed->gety());

			point* temp = traversed;
			point* temp_ref = ref.traversed->next;

			while (temp_ref != NULL)
			{
				temp->next = new point(temp_ref->getx(), temp_ref->gety());
				temp = temp->next;
				temp_ref = temp_ref->next;
			}
		}
		else
			traversed = NULL;


		return *this;
	}
	~stack()
	{
		point* temp = traversed;
		while (temp != NULL)
		{
			traversed = traversed->next;
			delete temp;
			temp = traversed;
		}
	}
};

#endif // !STACK_POINT_H
