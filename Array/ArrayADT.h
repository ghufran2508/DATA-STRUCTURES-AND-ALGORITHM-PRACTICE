#pragma once

#ifndef ARRAYADT_H
#define ARRAYADT_H

class ArrayADT
{
private:
	int* data;
	int size;
public:
	ArrayADT()
	{
		this->size = 10;
		data = new int[size];
	}
	ArrayADT(int size)
	{
		this->size = (size > 0) ? size : 10;
		data = new int[size];
	}
	ArrayADT(const ArrayADT& ref)
	{
		this->size = ref.size;
		this->data = new int[size];

		for (int i = 0; i < size; i++)
		{
			data[i] = ref.data[i];
		}
	}
	int getSize() const
	{
		return this->size;
	}
	int& operator[](int index)
	{
		return data[index];
	}
	int& operator[](int index)const
	{
		return data[index];
	}
	void resize(int size)
	{
		int* newdata = new int[this->size];

		for (int i = 0; i < this->size; i++)
		{
			newdata[i] = data[i];
		}

		delete[] data;
		
		data = new int[size];
		for (int i = 0; i < this->size; i++)
		{
			data[i] = newdata[i];
		}
		this->size = size;

		delete[] newdata;
		newdata = nullptr;
	}
	ArrayADT& operator= (const ArrayADT& ref)
	{
		if (this->data)
			delete[] this->data;

		this->size = ref.size;
		this->data = new int[this->size];

		for (int i = 0; i < this->size; i++)
		{
			data[i] = ref.data[i];
		}
		return *this;
	}
	~ArrayADT()
	{
		delete[] data;
		data = nullptr;
	}
};

#endif //ARRAYADT_H