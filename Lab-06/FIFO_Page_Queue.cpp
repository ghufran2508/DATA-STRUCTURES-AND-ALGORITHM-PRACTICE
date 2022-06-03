#include<iostream>

using namespace std;

class cirQueue{
    int front,rear;
    int* data;
    int size;
    int remove;
public:
    cirQueue(){
        size = 3;
        data = new int[size];

        rear=front=-1;

        remove = 0;
    }

    cirQueue(int size) {
        this->size = size > 0 ? size: 3;
        data = new int[this->size];

        rear=front=-1;
    }

    cirQueue(const cirQueue& ref) {
        this->size = ref.size;

        this->data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = ref.data[i];
        }

        this->front = ref.front;
        this->rear = ref.rear;
        this->remove = ref.remove;
    }

    ~cirQueue() {
        delete[] this->data;
    }

    void insert(int x){
        if (front==-1 && rear==-1){
            front=rear=0;
            data[rear]=x;
        }
        else{
            if ((rear+1)%size == front){
                cout << "Full Queue \n";
            }
            else{
                rear=(rear+1)%size;
                data[rear]=x;
            }
        }
    }
    bool CQempty(){
        if (front==-1){
            // cout << "Queue Empty \n";
            return true;
        }
        else
            return false;
    }
    bool CQFull(){
        if ((rear+1)%size == front){
            // cout <<"Queue is Full \n";
            return true;
        }
        else
            return false;
    }
    int CQDelete(){
        int rv;
        if (CQempty()){
            // cout << "Empty Queue \n";
            rv = -999;
        }
        else{
            rv = data[front];
            if (front == rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%size;
            }
        }
        return rv;
    }

    void update(int page) {
        if(CQempty()) {insert(page);}
        else {
            if(remove > rear) {
                remove=0;
            }
            else {
                data[remove] = page;
                remove = (remove+1)%size;
            }
        }
    }
};

void display(cirQueue& cq) {
    cirQueue newQu(cq);
    cout << endl << "Queue: ";
    while (!newQu.CQempty())
    {
        /* code */
        cout << newQu.CQDelete() << " ";
    }
    cout << endl << endl;
}

bool pageFault(cirQueue& cq, int page) {
    cirQueue newQu(cq);

    while(!newQu.CQempty()) {
        if(newQu.CQDelete() == page) return false;
    }
    return true;
}

void insertPage(cirQueue& cq, int& faults) {
    int page;
    cout << "Enter page number: ";
    cin >> page;


    if(cq.CQFull()) {
        if(pageFault(cq, page)) {
            cq.update(page);
            faults++;
        }
    }   
    else {
        if(pageFault(cq, page))
        {
            cq.insert(page);
            faults++;
        }
    }

    display(cq);
} 

int main() {
    int queueSize;
    int choice, fault = 0;

    cout << "Please Enter Queue Size: ";
    cin >> queueSize;

    cirQueue cq(queueSize);

    do {
        cout << "Please choose from the following." << endl;
        cout << "1. Enter Another Page" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        while(choice < 0 || choice > 1) {
            cin >> choice;
        }

        if(choice == 1) {
            insertPage(cq, fault);
        }


    }while(choice != 0);

    cout << "\nTotal Page Faults: " << fault << endl;

    return 0;
}