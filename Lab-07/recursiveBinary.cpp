#include<iostream>

using namespace std;

void recursiveBinary(long number) {
    if(number == 0) {cout << 0 << " "; return;}
    else {
        number/=2;

        recursiveBinary(number);
        cout << number % 2 << " ";
    }
}

int main() {
    recursiveBinary(12);

    return 0;
}