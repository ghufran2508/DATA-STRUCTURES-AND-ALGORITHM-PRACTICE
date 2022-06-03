#include<iostream>

using namespace std;

class Node {
    public:
        int number;
        Node* next;

        Node() {
            number = 0; next = NULL;
        } 
        Node(int x) {
            number = x; next = NULL;
        }
};

class LinkedList {
    Node* head;
    
    public:
    LinkedList() {
        head = NULL;
    }

    ~LinkedList() {
        Node* temp;

        while(head) {
            temp = head;
            
            head = head->next;

            delete temp;
        }
    }

    LinkedList(const LinkedList& ref) {
        head = NULL;

        Node* refHead = ref.head;

        while(refHead) {
            insert(refHead->number);
            refHead = refHead->next;
        }
    }

    LinkedList& operator=(const LinkedList& ref) {
        head = NULL;

        Node* refHead = ref.head;

        while(refHead) {
            insert(refHead->number);
            refHead = refHead->next;
        }
        return *this;
    }

    Node* getHead() {return this->head;}

    void insert(int x) {
        if(head == NULL) {
            head = new Node(x);
        }
        else {
            Node* temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = new Node(x);
        }
    }

    int getLength() {
        Node* temp = head;
        int count = 0;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    Node* getMiddle() {
        int length = getLength();

        Node* temp = head;
        for(int i = 0; i < length/2; i++) {
            temp = temp->next;
        }

        return temp;
    }

    void print() {
        Node* temp = head;

        while(temp) {
            cout << temp->number << " ";

            temp = temp->next;
        }
        cout << endl;
    }

    void reverse() {
        Node* next = head;
        Node* current = head;
        Node* prev = NULL;

        while(current) {
            next = current->next;

            current->next = prev;

            prev = current;

            current = next;
        }
        head = prev;
    }

    Node* reverseLinked(int n, Node* h) {
        if(!h) return NULL;

        Node* next = NULL;
        Node* current = h;
        Node* prev = NULL;
        int count = 0;

        while(current && count < n) {
            next = current->next;

            current->next = prev;

            prev = current;

            current = next;
            count++;
        }
        if(next != NULL) h->next = reverseLinked(n, next);

        return prev;
    }

    void reverse(int n) {
        head = reverseLinked(n, head);
    }

    bool isEmpty() {
        return head == NULL;
    }

    int top() {
        if(head) return head->number;
        else {
            return -INT16_MAX;
        }
    }

    void pop() {
        Node* temp = head;
        if(head != NULL) head = head->next;

        if(temp != NULL) delete temp;
    }
};

void removeDuplicates(LinkedList& ll) {
    Node* current = ll.getHead();
    Node* nextN;

    if(current == NULL) return;

    while(current->next != NULL) {
        if(current->number == current->next->number) {
            nextN = current->next->next;

            delete current->next;

            current->next = nextN;
        }

        current = current->next;
    }
}

LinkedList merger(LinkedList ref1, LinkedList ref2) {
    LinkedList ll;

    while(!ref1.isEmpty() && !ref2.isEmpty()) {
        if(ref1.top() <= ref2.top()) {
            ll.insert(ref1.top());
            ref1.pop();
        }
        else {
            ll.insert(ref2.top());
            ref2.pop();
        }
    }

    while(!ref1.isEmpty()) {
        ll.insert(ref1.top());
        ref1.pop();
    }

    while(!ref2.isEmpty()) {
        ll.insert(ref2.top());
        ref2.pop();
    }

    return ll;
}



int main() {
    LinkedList ll;

    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    ll.insert(4);
    ll.insert(4);
    ll.insert(5);
    ll.insert(6);
    ll.insert(7);

    ll.print();

    cout << ll.getLength() << endl;
    cout << ll.getMiddle()->number << endl;

    ll.reverse();

    ll.print();

    ll.reverse(3);

    ll.print();

    removeDuplicates(ll);

    ll.print();


    LinkedList ref1;
    LinkedList ref2;

    ref1.insert(1);
    ref2.insert(2);
    ref1.insert(3);
    ref2.insert(4);
    ref1.insert(5);
    ref2.insert(6);
    ref1.insert(7);
    ref2.insert(8);


    cout << "R1: " ;
    ref1.print();
    cout << "R2: " ;
    ref2.print();

    LinkedList result = merger(ref1, ref2);

    cout << "Result after merge: ";
    result.print();

    return 0;
}