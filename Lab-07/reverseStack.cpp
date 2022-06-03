#include<iostream>
#include<stack>

using namespace std;

void insertAtBOttom(stack<int>& st, int num) {
    if(st.empty()) st.push(num);
    else {
        int top = st.top();
        st.pop();

        insertAtBOttom(st, num);
        st.push(top);
    }
}

void reverseStack(stack<int>& st) {
    if(st.empty()) return;
    else {
        int num = st.top();
        st.pop();

        reverseStack(st);

        insertAtBOttom(st, num);
    }
}

int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while(!st.empty()) {
        cout << st.top() << " " ;
        st.pop();
    }

    return 0;
}