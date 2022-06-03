#include<iostream>
#include"XDLinkedList.h"

using namespace std;

//Code complexity f(x) = 2
Node* XOR(Node* a, Node* b)
{
	return (Node*)((int(a) ^ int(b)));	//2
}

//Code complexity f(x) = 1
XDLinkList::XDLinkList()
{
	head = tail = NULL; // 1
}
//Code complexity (worst case) f(x) = 11n + 22
XDLinkList::XDLinkList(const XDLinkList& ref)
{
	if (ref.head != NULL)	//1
	{
		head = new Node(ref.head->data);	//2
		
		Node* current = head;	//1
		Node* next, * prev = NULL;	//1
		Node* ref_current = ref.head;	//1
		Node* ref_next, * ref_prev = NULL;	//1

		ref_next = XOR(ref_current->npx, prev);	//2
		ref_prev = ref_current;	//1
		ref_current = ref_next;	//1

		while (ref_current != ref.tail)	//n+1
		{
			Node* newnode = new Node(ref_current->data);	//2

			newnode->npx = XOR(current, NULL);	//2
			next = newnode;	//1
			current->npx = XOR(prev, next);	//2
			prev = current;	//1
			current = next;	//1
		
			ref_next = XOR(ref_current->npx, ref_prev);	//2
			ref_prev = ref_current;	//1
			ref_current = ref_next;	//1
		}	//->11n +1

		Node* newnode = new Node(ref_current->data);	//2

		newnode->npx = XOR(current, NULL);	//2
		next = newnode;	//1
		current->npx = XOR(prev, next);	//2
		prev = current;	//1
		current = next;	//1

		tail = current;	//1
	}
	else
	{
		head = tail = NULL;	//1
	}
}

//Code complexity(worst case) = f(x) = 7n + 5
XDLinkList::~XDLinkList()
{
	Node* current = head;	//1
	Node* next, * prev = NULL;	//1
	Node* todelete;	//1

	while (current != NULL) //n+1
	{
		todelete = prev;	//1
		next = XOR(current->npx, prev);	//2
		prev = current;	//1
		current = next;	//1
		delete todelete;	//1
	}
	delete prev;	//1
	head = tail = NULL;	//1
}

//Code complexity(worst case) = f(x) = 10
void XDLinkList::insertAtHead(int value)
{
	Node* newnode = new Node(value);	//2

	if (head == NULL)	//1
	{
		head = tail = newnode; //1
	}
	else
	{
		Node* next = XOR(head->npx,NULL); //2
		head->npx = XOR(next, newnode);   //2
		newnode->npx = XOR(head, NULL);   //2
		head = newnode;					  //1
	}
}

//Code complexity(worst case) = f(x) = 10
void XDLinkList::insertAtTail(int value)
{
	Node* newnode = new Node(value);	//2

	if (tail == NULL)	//1
	{
		head = tail = newnode;
	}
	else
	{
		Node* prev = XOR(tail->npx, NULL);	//2
		tail->npx = XOR(prev, newnode);	//2
		newnode->npx = XOR(tail, NULL); //2
		tail = newnode;					//1
	}
}

//Code complexity(worst case) = f(x) = 11
int XDLinkList::RemoveAtHead()
{
	if (head == NULL)	//1
	{
		exit(0);
	}
	Node* temp = head;	//1

	if (head == tail)	//1
	{
		head = tail = NULL;	//1
	}
	else
	{
		head = head->npx;	//1
		Node* next = XOR(head->npx, temp); //2
		head->npx = XOR(next, NULL); //2
	}
	int value = temp->data;	//1
	delete temp; //1
	return value; ///1
}

//Code complexity(worst case) = f(x) = 11
int XDLinkList::RemoveAtTail()
{
	if (tail == NULL)	//1
	{
		exit(0);	//1
	}
	Node* temp = tail;	//1

	if (head == tail)	//1
	{
		head = tail = NULL;	//1
	}
	else
	{
		tail = tail->npx;	//1
		Node* prev = XOR(tail->npx,temp);	//2
		tail->npx = XOR(prev, NULL);	//2
	}
	int value = temp->data;	//1
	delete temp;	//1
	return value;	//1
}

//Code complexity(worst case) = f(x) = 6n+6
void XDLinkList::insertAtIndex(int index, int val)
{
	Node* current = head;	//1
	Node* next, * prev = NULL;	//1

	for (int i = 0; i < index && current != NULL; i++)	//1 + n+1 + n
	{
		next = XOR(current->npx, prev);	//2
		prev = current;	//1
		current = next;	//1
	}//n*4			->6n+2

	if (current == NULL) return;	//1
	current->data = val;			//1
}

//Code complexity(worst case) = f(x) = 6n + 17
int XDLinkList::removeAtIndex(int index)
{
	if (index < 0) exit(0);	//1
	if (index == 0)		//1
	{
		return this->RemoveAtHead();	//9
	}
	else
	{
		Node* current = head;		//1
		Node* next, * prev = NULL;	//1

		for (int i = 0; i < index && current != NULL; i++)	//1 + n+1 + n
		{
			next = XOR(current->npx, prev);	//2
			prev = current;	//1
			current = next;	//1
		}//n*4						-> 6n + 2

		if (current == NULL) exit(0);	//1
		if (current == tail)	//1
		{
			return this->RemoveAtTail();	//9
		}

		next = XOR(current->npx, prev);		//2
		Node* pre_prev = XOR(prev->npx, current);	//2
		Node* nex_next = XOR(next->npx, current);	//2
		prev->npx = XOR(pre_prev, next);	//2
		next->npx = XOR(nex_next, prev);	//2

		int value = current->data;	//1
		delete current;		//1
		return value;	//1
	}
}

//Code complexity(worst case) = f(x) = 6n+19
void XDLinkList::insertBefore(int index, int val)
{
	if (index < 0) exit(0);	//1
	if (index == 0)	//1
	{
		this->insertAtHead(val);	//9
	}
	else
	{
		Node* current = head;	//1
		Node* next, * prev = NULL;	//1
		int count = 0;			//1

		while (count < index && current != NULL)	//n+1
		{
			next = XOR(current->npx, prev);	//2
			prev = current;	//1
			current = next;	//1
			count++;		//1
		}			//->6n+1
		if (current == NULL)	//1
		{
			if (count == index)	//1
			{
				this->insertAtTail(val);	//9
			}
			return;	//1
		}

		Node* newnode = new Node(val);	//2

		Node* pre_prev = XOR(prev->npx, current);	//2
		next = XOR(current->npx, prev);		//2
		prev->npx = XOR(pre_prev, newnode);	//2
		newnode->npx = XOR(prev, current);	//2
		current->npx = XOR(newnode, next);	//2
	}
}

//Code complexity(worst case) = f(x) = 6n+19
int XDLinkList::removeBefore(int index)
{
	if (index <= 0) exit(0);	
	if (index == 1)
	{
		return this->RemoveAtHead();
	}
	else
	{
		Node* current = head;
		Node* next, * prev = NULL;

		for (int i = 0; i < index-1 && current != NULL; i++)
		{
			next = XOR(current->npx, prev);
			prev = current;
			current = next;
		}
		if (current == NULL) exit(0);

		Node* pre_prev = XOR(prev->npx, current);
		next = XOR(current->npx, prev);
		prev->npx = XOR(pre_prev, next);
		Node* nex_next = XOR(next->npx, current);
		next->npx = XOR(nex_next, prev);

		int value = current->data;
		delete current;
		return value;
	}
}
//Code complexity(worst case) = f(x) = 6n+21
void XDLinkList::insertAfter(int index, int val)
{
	if (index < 0) return;

	Node* current = head;
	Node* next, * prev = NULL;

	for (int i = 0; i < index && current != NULL; i++)
	{
		next = XOR(current->npx, prev);
		prev = current; 
		current = next;
	}
	if (current == NULL) return;
	else
	{
		if (current == tail)
		{
			this->insertAtTail(val);
		}
		else
		{
			Node* newnode = new Node(val);

			next = XOR(current->npx, prev);
			Node* nex_next = XOR(next->npx, current);
			next->npx = XOR(nex_next, newnode);
			newnode->npx = XOR(current, next);
			current->npx = XOR(prev, newnode);
		}
	}
}
//Code complexity(worst case) = f(x) = 6n+19
int XDLinkList::removeAfter(int index)
{
	if (index < 0) exit(0);

	Node* current = head;
	Node* next, * prev = NULL;

	for (int i = 0; i < index && current != NULL; i++)
	{
		next = XOR(current->npx, prev);
		prev = current;
		current = next;
	}
	if (current == NULL) exit(0);

	next = XOR(current->npx, prev);

	if (next == tail)
	{
		return this->RemoveAtTail();
	}

	Node* nex_next = XOR(next->npx, current);
	current->npx = XOR(prev, nex_next);
	Node* n2_next = XOR(next, nex_next->npx);
	nex_next->npx = XOR(current, n2_next);

	int value = next->data;
	delete next;
	return value;
}
//Code complexity(worst case) = f(x) = 7n+6
int XDLinkList::getIndex(int value)
{
	Node* current = head;	//1
	Node* next, * prev = NULL;		//1
	int index = 0;			//1

	while (current != tail)		//n+1
	{
		if (current->data == value)	//1
			return index;	//1

		next = XOR(current->npx, prev);	//2
		prev = current;	//1
		current = next;	//1
		index++;	//1
	}		// -> 7n+1
	
	if (current->data == value)	//1
		return index;	//1

	return -1;	//1
}
//Code complexity(worst case) = f(x) = 6n+7
int& XDLinkList::operator[](int index)
{
	if (index < 0) exit(0);

	Node* current = head;
	Node* next, * prev = NULL;

	for (int i = 0; i < index && current != NULL; i++)
	{
		next = XOR(current->npx, prev);
		prev = current;
		current = next;	
	}//6n+2

	if (current == NULL) exit(0);	//1
	
	return current->data;	//1
}
//Code complexity(worst case) = f(x) = 18n + 28
XDLinkList& XDLinkList::operator=(const XDLinkList& ref)
{
	if (this->head)
	{
		Node* current = head;
		Node* next, * prev = NULL;
		Node* todelete;

		while (current != NULL)
		{
			todelete = prev;
			next = XOR(current->npx, prev);
			prev = current;
			current = next;
			delete todelete;
		}
		delete prev;
		head = tail = NULL;
	}

	if (ref.head != NULL)
	{
		head = new Node(ref.head->data);

		Node* current = head;
		Node* next, * prev = NULL;
		Node* ref_current = ref.head;
		Node* ref_next, * ref_prev = NULL;

		ref_next = XOR(ref_current->npx, prev);
		ref_prev = ref_current;
		ref_current = ref_next;

		while (ref_current != ref.tail)
		{
			Node* newnode = new Node(ref_current->data);

			newnode->npx = XOR(current, NULL);
			next = newnode;
			current->npx = XOR(prev, next);
			prev = current;
			current = next;

			ref_next = XOR(ref_current->npx, ref_prev);
			ref_prev = ref_current;
			ref_current = ref_next;
		}

		Node* newnode = new Node(ref_current->data);

		newnode->npx = XOR(current, NULL);
		next = newnode;
		current->npx = XOR(prev, next);
		prev = current;
		current = next;

		tail = current;
	}
	else
	{
		head = tail = NULL;
	}

	return *this;
}
//Code complexity(worst case) = f(x) = 1
bool XDLinkList::isEmpty()
{
	return (head == NULL);	//1
}

void XDLinkList::print()
{
	Node* temp = head;
	Node* next, *prev = NULL;

	while (prev != tail)
	{
		cout << temp->data << " ";

		next = XOR(temp->npx, prev);
		prev = temp;
		temp = next;
	}
	cout << endl;
}