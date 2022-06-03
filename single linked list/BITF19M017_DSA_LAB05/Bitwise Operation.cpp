#include<iostream>
#include"XDLinkedList.h"

using namespace std;

int main()
{
	XDLinkList xdll;

	xdll.insertAtHead(3);
	xdll.insertAtHead(4);
	xdll.insertAtHead(6);
	xdll.insertAtHead(8);

	

	xdll.print();
	return 0;
}
