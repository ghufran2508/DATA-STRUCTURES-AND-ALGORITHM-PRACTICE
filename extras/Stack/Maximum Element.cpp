#include<iostream>

using namespace std;

template <class datatype>
class Stack
{
	int size;
	int top;
	datatype* data;
	
	void resize()
	{
		datatype* newdata = new datatype[size];
		
		for (int i = 0; i < size; i++)
		{
			newdata[i] = data[i];
		}

		delete[] data;

		data = new datatype[size * 2];
		for (int i = 0; i < size; i++)
		{
			data[i] = newdata[i];
		}
		size *= 2;
		delete[] newdata;
		newdata = nullptr;
	}
public:
	Stack()
	{
		size = 5;
		top = -1;
		data = new datatype[size];
	}
	~Stack()
	{
		delete[] data;
		data = nullptr;
	}
	bool isfull()
	{
		return (top == size - 1);
	}
	bool isEmpty()
	{
		return (top == -1);
	}
	void push(datatype value)
	{
		if (isfull())
		{
			resize();
		}
		data[++top] = value;
	}
	datatype pop()
	{
		if (isEmpty())
		{
			exit(0);
		}		
		return data[top--];
	}
	int getSize() const
	{
		return this->size;
	}
};

int findmax(class Stack<int> mystack)
{
	int max = 0;

	for (int i = 0; !mystack.isEmpty(); i++)
	{
		int temp = mystack.pop();
		if (temp > max) max = temp;
	}

	return max;
}


int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int N;
	cin >> N;

	Stack<int> mystack;

	for (int i = 1; i <= N; i++)
	{
		int query1, query2;

		cin >> query1;
		if (query1 == 1)
		{
			cin >> query2;
			mystack.push(query2);
		}
		else if (query1 == 2)
		{
			mystack.pop();
		}
		else
		{
			cout << findmax(mystack) << endl;
		}
	}

	return 0;
}
