#include<iostream>

using namespace std;

class p_queue
{
    int front, rear;
    int* data;
    int capacity;
public:
    p_queue() {
        rear = front = -1;
        capacity = 10;
        data = new int[capacity];
    }
    p_queue(int size) {
        rear = front = -1;
        this->capacity = (size > 0) ? size : 10;
        data = new int[capacity];
    }
    bool isFull() {
        return (rear == capacity - 1);
    }
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    //rather we can use priority insert or priority dequeue, i am implementing both
    void p_insert(int x) {
        if (rear == -1) {   // first item is being inserted
            front = rear = 0;
            data[rear] = x;
        }
        else if (isFull()) {
            cout << "\nLast index filled in queue \n";
        }
        else
        {
            if (data[front] < x)
            {
                for (int i = rear+1; i > front; i--)
                {
                    data[i] = data[i-1];
                }
                data[front] = x;
                rear++;
            }
            else
            {
                int count = front;
                while (data[count] > x && count <= rear)
                {
                    count++;
                }
                for (int i = rear; i >= count; i--)
                {
                    data[i+1] = data[i];
                }
                data[count] = x;
                rear++;
            }
        }
    }
    void insert(int x) {
        if (rear == -1) {   // first item is being inserted
            front = rear = 0;
            data[rear] = x;
        }
        else {
            if (isFull())
                cout << "\nLast index filled in queue \n";
            else
                data[++rear] = x;
        }
    }
    int p_dequeue() {
        if (!isEmpty()) {
            int max = data[front];
            
            for (int i = front; i <= rear; i++)
            {
                if (data[i] > max)
                    max = data[i];
            }

            if (data[front] == max)
            {
                return data[front++];
            }
            int index = front;
            for (; index <= rear; index++)
            {
                if (data[index] == max)
                    break;
            }
            int value = data[index];
            for (int i = index; i <= rear; i++)
            {
                data[i] = data[i + 1];
            }
            rear--;
            return value;
        }
        else
        {
            cout << "Queue is empty ";
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
    ~p_queue()
    {
        delete[] data;
        data = NULL;
    }
};

int main()
{
    p_queue pq;

    pq.p_insert(9);
    pq.p_insert(4);
    pq.p_insert(7);
    pq.p_insert(91);
    pq.p_insert(90);
    pq.insert(35);
    pq.insert(361);
    pq.insert(31);
    pq.insert(34);
    pq.p_insert(901);

    pq.show();
    cout << endl;

    while (!pq.isEmpty())
    {
        cout << pq.p_dequeue() << endl;
    }

    return 0;
}
