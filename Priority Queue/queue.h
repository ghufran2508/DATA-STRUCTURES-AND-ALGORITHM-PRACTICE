#pragma once
#include <iostream>

using namespace std;


class MyQueue
{
    int* arr;       // array to store queue elements
    int* priorities;
    int capacity;   // maximum capacity of the queue
    int front;      // this points to the front element in the queue
    int back;       // this points to the last element in the queue
    int size;      // current size of the queue

public:
    MyQueue(int);     // parameterized constructor
    ~MyQueue();                   // destructor

    int count();
    bool isEmpty();
    bool isFull();
    void enQueue(int x, int p);
    int deQueue();
    int peek();
    void printQueue();

    int getSize();

    int priorityDequeue();
};