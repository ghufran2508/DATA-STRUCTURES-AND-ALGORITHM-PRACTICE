#pragma once

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include<iostream>
#include<string>
#include<queue>

using namespace std;

class Student
{
	friend class StudentMaxHeap;
private:
	string name;
	double cgpa;
	int rollNumber;
public:
	Student()
	{
		name = "";
		cgpa = 0.0;
		rollNumber = 00;
	}
	Student(string name, double cgpa, int rl)
	{
		this->name = name;
		this->cgpa = (cgpa > 0 && cgpa <= 4.0) ? cgpa : 0;
		this->rollNumber = (rl > 0) ? rl : 0;
	}

	void setName(string name)
	{
		this->name = name;
	}
	void setCgpa(double cgpa)
	{
		this->cgpa = (cgpa > 0 && cgpa <= 4.0) ? cgpa : 0;
	}
	void setRollNum(int rl)
	{
		this->rollNumber = (rl > 0) ? rl : 0;
	}

	string getName() const
	{
		return this->name;
	}
	double getCGPA() const
	{
		return this->cgpa;
	}
	int getRollNumber() const
	{
		return this->rollNumber;
	}

	Student& operator=(const Student& ref)
	{
		this->name = ref.name;
		this->cgpa = ref.cgpa;
		this->rollNumber = ref.rollNumber;

		return *this;
	}

	bool operator<(const Student& ref)
	{
		if (this->cgpa == ref.cgpa)
		{
			return this->rollNumber < ref.rollNumber;
		}
		else
			return this->cgpa < ref.cgpa;
	}
	bool operator<=(const Student& ref)
	{
		if (this->cgpa == ref.cgpa)
		{
			return this->rollNumber <= ref.rollNumber;
		}
		else
			return this->cgpa <= ref.cgpa;
	}
	bool operator>(const Student& ref)
	{
		if (this->cgpa == ref.cgpa)
		{
			return this->rollNumber > ref.rollNumber;
		}
		else
			return this->cgpa > ref.cgpa;
	}
	bool operator>=(const Student& ref)
	{
		if (this->cgpa == ref.cgpa)
		{
			return this->rollNumber >= ref.rollNumber;
		}
		else
			return this->cgpa >= ref.cgpa;
	}
	bool operator==(const Student& ref)
	{
		return (this->cgpa == ref.cgpa && this->name == ref.name && this->rollNumber == ref.rollNumber);
	}
	bool operator!=(const Student& ref)
	{
		return (this->cgpa != ref.cgpa && this->name != ref.name && this->rollNumber != ref.rollNumber);
	}

	friend ostream& operator<<(ostream&, const Student& ref);
};

ostream& operator<<(ostream& out, const Student& ref)
{
	out << "Student Name: " << ref.name << endl;
	out << "Roll Number: " << ref.rollNumber << endl;
	out << "CGPA: " << ref.cgpa << endl;
	
	return out;
}

class StudentMaxHeap
{
	Student* arr; //Array of students which, arranged like a Max Heap 
	int curSize; //Current number of students present in the heap 
	int maxSize; //Maximum number of students that can be present in heap
public:
	StudentMaxHeap(int size) //Constructor 
	{
		this->maxSize = (size > 1) ? size : 1;
		this->curSize = 0;

		this->arr = new Student[maxSize];
	}
	~StudentMaxHeap() //Destructor 
	{
		delete[] arr;
		arr = NULL;
	}
	bool isEmpty() //Checks whether the heap is empty or not 
	{
		return this->curSize == 0;
	}
	bool isFull() //Checks whether the heap is full or not 
	{
		return (this->curSize == this->maxSize);
	}
	StudentMaxHeap& operator = (StudentMaxHeap& ref) //Overloaded assignment operator 
	{
		this->maxSize = ref.maxSize;
		this->arr = new Student[this->maxSize];

		this->curSize = ref.curSize;

		for (int i = 0; i < curSize; i++)
		{
			this->arr[i] = ref.arr[i];
		}

		return *this;
	}
	// Methods…
	bool insert(int rollNo, string name, double cgpa)
	{
		if (isFull())
			return false;
		Student newStudent(name, cgpa, rollNo);
		
		this->arr[this->curSize] = newStudent;

		int i = this->curSize;
		int parent;

		while (i > 0)
		{
			parent = ((i - 1) / 2);
			if (arr[i] > arr[parent])
			{
				Student temp = arr[i];
				arr[i] = arr[parent];
				arr[parent] = temp;
			}
			i = parent;
		}
		this->curSize++;
		return true;
	}
	Student extractTopper()
	{
		if (isEmpty()) exit(0);

		Student topper = arr[0];

		arr[0] = arr[this->curSize-1];

		int i = 0;
		int left = (2 * i) + 1;
		int right = (2 * i) + 2;

		while (i < curSize)
		{
			if (arr[i] < arr[left])
			{
				Student temp = arr[i];
				arr[i] = arr[left];
				arr[left] = temp;

				i = left;
			}
			else if (arr[i] < arr[right])
			{
				Student temp = arr[i];
				arr[i] = arr[right];
				arr[right] = temp;

				i = right;
			}
			break;
		}
		this->curSize--;
		return topper;
	}
	void displayStudentList()
	{
		queue<Student> std_q;

		int parent = 0;
		int left_child = 2 * parent + 1;
		int right_child = 2 * parent + 2;

		std_q.push(arr[parent]);

		for (int i = 0; i < curSize; i++)
		{
			left_child = 2 * parent + 1;
			right_child = 2 * parent + 2;
			parent++;

			if (arr[left_child] > arr[right_child] && left_child < curSize)
			{
				std_q.push(arr[left_child]);
				std_q.push(arr[right_child]);
			}
			else if (arr[left_child] < arr[right_child] && right_child < curSize)
			{
				std_q.push(arr[right_child]);
				std_q.push(arr[left_child]);
			}
		}

		while (!std_q.empty())
		{
			cout << std_q.front() << endl;
			std_q.pop();
		}
	}
	void printHeap()
	{
		if (this->curSize > 0)
		{
			int index = 0;
			cout << arr[index] << endl;
			index++;

			bool check = false;
			int i = 1;
			int print = 1;
			for (; ; index++)
			{
				for (int i = 0; i < pow(index, 2); i++)
				{
					if (print == curSize) {
						check = true;
						break;
					}

					cout << arr[print++] << " ";
				}
				if (check)
					break;
				cout << endl;
			}
		}
	}
};


#endif // !MAX_HEAP_H
