#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

class queue {
    int front, rear;
    int* data;
    int capacity;
public:
    queue() {
        rear = front = -1;
        capacity = 10;
        data = new int[capacity];
    }
    queue(int size) {
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
    int dequeue() {
        if (!isEmpty()) {
            return (data[front++]);
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
    ~queue()
    {
        delete[] data;
        data = NULL;
    }
};

#endif // !QUEUE_H
