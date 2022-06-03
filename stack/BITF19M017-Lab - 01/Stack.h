#pragma once

template <class datatype>
class Stack
{
    int size;
    int top;
    datatype* data;

    void resize()
    {
        datatype* newdata = new datatype[size];

        for (int i = 0; i < size; i++)
        {
            newdata[i] = data[i];
        }

        delete[] data;

        data = new datatype[size * 2];
        for (int i = 0; i < size; i++)
        {
            data[i] = newdata[i];
        }
        size *= 2;
        delete[] newdata;
        newdata = nullptr;
    }
public:
    Stack()
    {
        size = 5;
        top = -1;
        data = new datatype[size];
    }
    ~Stack()
    {
        delete[] data;
        data = nullptr;
    }
    bool isfull()
    {
        return (top == size - 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void push(datatype value)
    {
        if (isfull())
        {
            resize();
        }
        data[++top] = value;
    }
    datatype pop()
    {
        if (isEmpty())
        {
            exit(0);
        }
        return data[top--];
    }
    int getSize() const
    {
        return this->size;
    }
};
