#include<iostream>
#include"queue.h"

using namespace std;

int main()
{
	MyQueue check(5);

	check.enQueue(10,4);
	check.enQueue(20,1);
	check.enQueue(3,2);
	check.enQueue(4,5);
	check.enQueue(30,2);

	cout << check.priorityDequeue() << endl;
	cout << check.priorityDequeue() << endl;
	cout << check.priorityDequeue() << endl;
	cout << check.priorityDequeue() << endl;
	cout << check.priorityDequeue() << endl;

	return 0;
}