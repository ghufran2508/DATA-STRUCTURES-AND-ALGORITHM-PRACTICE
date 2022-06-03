#include<iostream>
#define SIZE 5
using namespace std;

class cirQueue{
    int front,rear;
    int data[SIZE];
public:
    cirQueue(){
        rear=front=-1;
    }
    void insert(int x){
        if (front==-1 && rear==-1){
            front=rear=0;
            data[rear]=x;
        }
        else{
            if ((rear+1)%SIZE == front){
                cout << "Full Queue \n";
            }
            else{
                rear=(rear+1)%SIZE;
                data[rear]=x;
            }
        }
    }
    bool CQempty(){
        if (front==-1){
            cout << "Queue Empty \n";
            return true;
        }
        else
            return false;
    }
    bool CQFull(){
        if ((rear+1)%SIZE == front){
            cout <<"Queue is Full \n";
            return true;
        }
        else
            return false;
    }
    int CQDelete(){
        int rv;
        if (CQempty()){
            cout << "Empty Queue \n";
            rv = -999;
        }
        else{
            rv = data[front];
            if (front == rear){
                front = rear = -1;
            }
            else{
                front = (front+1)%SIZE;
            }
        }
        return rv;
    }
};

int main(){
    cirQueue q1;
    q1.CQempty();
    q1.CQFull();
    q1.insert(19);
    q1.insert(45);
    q1.insert(78);
    q1.insert(16);
    q1.insert(55);

    q1.CQempty();
    q1.CQFull();

    q1.insert(55);

    cout << q1.CQDelete()<<endl;
    cout << q1.CQDelete()<<endl;
    cout << q1.CQDelete()<<endl;
    cout << q1.CQDelete()<<endl;
    q1.CQempty();
    q1.CQFull();
    cout << q1.CQDelete()<<endl;

    q1.CQempty();
    q1.CQFull();

    q1.insert(9);
    q1.insert(5);
    q1.insert(8);

    q1.CQempty();
    q1.CQFull();

    cout << q1.CQDelete()<<endl;
    cout << q1.CQDelete()<<endl;
    cout << q1.CQDelete()<<endl;
    q1.CQempty();
    q1.CQFull();
}
