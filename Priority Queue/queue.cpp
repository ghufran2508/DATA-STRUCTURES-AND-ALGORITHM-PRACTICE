#include "queue.h"

MyQueue::MyQueue(int size)
{
    arr = new int[size];
    priorities = new int[size];
    capacity = size;
    front = 0;
    back = -1;
    this->size = 0;
}

MyQueue::~MyQueue() {
    delete[] arr;
    delete[] priorities;
}

int MyQueue::count() {
    return size;
}

bool MyQueue::isEmpty() {
    return (count() == 0);
}

bool MyQueue::isFull() {
    return (count() == capacity);
}

void MyQueue::enQueue(int value, int priority)
{
    if (isFull())
    {
        cout << "Queue is Full\n";
    }


    back = (back + 1) % capacity;
    arr[back] = value;
    priorities[back] = priority;
    size++;
}

int MyQueue::deQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty\n";
    }
    int value = arr[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}

int MyQueue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
    }
    return arr[front];
}

void MyQueue::printQueue()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[(i + front) % capacity] << endl;
    }

}

int MyQueue::getSize()
{
    return size;
}

int MyQueue::priorityDequeue()
{
    int min = 999;

    for (int i = 0; i < size; i++)
    {
        if (priorities[(i + front) % capacity] < min)
            min = priorities[(i + front) % capacity];

        if (priorities[(i+front)%capacity] == 2)
        {
            
            int value = arr[(i + front) % capacity];

            for (int j = i; j < size-1; j++)
            {
                arr[j] = arr[j + 1];
                priorities[j] = priorities[j + 1];
            }

            size--;
            return value;
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (priorities[(i + front) & capacity] == min)
        {
            int value = arr[(i + front) % capacity];

            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
                priorities[j] = priorities[j + 1];
            }

            size--;
            return value;
        }
    }

    return 0;
}

//void MyQueue::push(int value)
//{
//    MyQueue newqueue(this->size);
//
//    while (!this->isEmpty())
//    {
//        newqueue.enQueue(this->deQueue());
//    }
//    this->enQueue(value);
//    while (!newqueue.isEmpty())
//    {
//        this->enQueue(newqueue.deQueue());
//    }
//}
//
//int MyQueue::pop()
//{
//    MyQueue newqueue(this->size);
//
//    for (int i = 0; i < this->capacity - 1; i++)
//    {
//        newqueue.enQueue(this->deQueue());
//    }
//    int value = this->deQueue();
//
//    while (newqueue.isEmpty())
//        this->enQueue(newqueue.deQueue());
//
//    return value;
//}