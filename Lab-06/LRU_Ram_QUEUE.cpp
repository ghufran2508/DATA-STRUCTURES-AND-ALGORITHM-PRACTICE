#include<iostream>

using namespace std;


class Queue{
    int rear;
    int* data;
    int size;
public:
    Queue(){
        size = 9;
        data = new int[size];

        rear=-1;
    }

    Queue(int size) {
        this->size = size > 0 ? size: 9;
        data = new int[this->size];

        rear=-1;
    }

    Queue(const Queue& ref) {
        this->size = ref.size;

        this->data = new int[size];
        for(int i = 0; i < size; i++) {
            data[i] = ref.data[i];
        }

        this->rear = ref.rear;
    }

    ~Queue() {
        delete[] this->data;
    }

    void insert(int x){
        for(int i = rear; i >= 0; i--) {
            data[i+1] = data[i];
        }

        data[0] = x;


        if(!QFull()) {
            rear++;
        }
    }
    bool Qempty(){
        return rear == -1;
    }
    bool QFull(){
        return rear == size - 1;
    }

    int QDelete(){
        int rv;
        if (Qempty()){
            // cout << "Empty Queue \n";
            rv = -999;
        }
        else{
            rv = data[0];

            for(int i = 1; i < rear; i++) {
                data[i-1] = data[i];
            }

            rear--;
        }
        return rv;
    }

    void printLRUCache() {
        cout << "\nQueue: ";

        for(int i = 0; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl << endl;
    }
};



int main() {
    int size;

    cout << "Enter the size of queue: ";
    cin >> size;

    Queue q(size);

    int page;

    do {
        cout << "Enter any page number or -1 to exit.";
        cin >> page;

        if(page < 0) break;    

        q.insert(page);
        q.printLRUCache();
    }while(1);

    q.printLRUCache();

    return 0;
}