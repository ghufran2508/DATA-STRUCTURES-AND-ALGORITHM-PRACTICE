#include<iostream>

using namespace std;

class queue {
    int front, rear;
    string* data;
    int capacity;
public:
    queue() {
        rear = front = -1;
        capacity = 100;
        data = new string[capacity];
    }
    queue(int size) {
        rear = front = -1;
        this->capacity = (size > 0) ? size : 10;
        data = new string[capacity];
    }
    bool isFull() {
        return (rear == capacity - 1);
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    void insert(string x) {
        if (rear == -1) {   // first item is being inserted
            front = rear = 0;
            data[rear] = x;
        }
        else {
            if (isFull()){}
                // cout << "\nLast index filled in queue \n";
            else
                data[++rear] = x;
        }
    }
    string dequeue() {
        if (!isEmpty()) {
            return (data[front++]);
        }
        else
        {
            // cout << "Queue is empty ";
            exit(0);
        }
    }
    void show() {
        int t;
        if (!isEmpty()) {
            t = front;
            while (t <= rear)
                cout << data[t++] << " - ";
        }
        else {
            cout << "No data in queue";
        }
    }
    ~queue()
    {
        delete[] data;
        data = NULL;
    }
};

int binaryToDecimal(string binary) {
    int num = 0;
    int mul = 1;

    for(int i = binary.length()-1; i >= 0; i--) {
        int temp =  binary[i]-'0';

        int add = mul*temp;

        num+=add;
        mul *= 2;
    } 

    return num;
}

void calculate(int num) {
    queue q;

    q.insert("1");
    cout << "1" << ", ";

    while(!q.isEmpty()) {
        string binary = q.dequeue();

        

        if(binaryToDecimal(binary+"0") == num) {
            cout << binary + "0" <<endl;
            break;
        } 
        if(binaryToDecimal(binary+"1") == num) {
            cout << binary + "1" <<endl;
            break;
        }

        q.insert(binary+"0");
        q.insert(binary+"1");

        cout << binary + "0, ";
        cout << binary + "1, ";
    }
}

int main() {
    int number;
    cout << "Input: ";
    cin >> number;

    calculate(number);

    return 0;
}