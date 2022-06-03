#include <bits/stdc++.h>

using namespace std;

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

// Complete the isBalanced function below.
string isBalanced(string s) {

    Stack<char> mystack;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            mystack.push(s[i]);
        }
        else
        {
            if(mystack.isEmpty())
            {
                return "NO";
            }
            
            char latestbracket = mystack.pop();
            
            if(latestbracket == '(' && s[i] != ')')
            {
                return "NO";
            }
            if(latestbracket == '{' && s[i] != '}')
            {
                return "NO";
            }
            if(latestbracket == '[' && s[i] != ']')
            {
                return "NO";
            }
        }
    }
    
    if(mystack.isEmpty())
    return "YES";
    else {
    return "NO";
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}

