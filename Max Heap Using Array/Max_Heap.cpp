#include<iostream>
#include"Max_Heap.h"

using namespace std;

int main()
{
	StudentMaxHeap smx(5);

	smx.insert(1, "A", 1.1);
	smx.insert(2, "B", 2.1);
	smx.insert(3, "C", 3.1);
	smx.insert(4, "D", 3.3);
	smx.insert(5, "E", 3.9);

	
	//smx.printHeap();
	smx.displayStudentList();

	return 0;
}