#include<iostream>

using namespace std;

void replace(char *str, char from, char to) {
    if(str[0] == '\0') return;
    else {
        if(str[0] == from) {
            str[0] = to;
        }

        replace(str+1, from, to);
    }
}

int main() {

    char str[5] = {'s', 't', 'e', 'v', 'e'};

    replace(str, 'e', 'a');

    cout << str << endl;

    return 0;
}