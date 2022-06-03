#include<iostream>

using namespace std;

int sumOfDigits(long number) {
    if(number <= 9) return number;
    else {
        int last = number % 10;
        number = number / 10;

        last += sumOfDigits(number);

        return last;
    }
}

int main() {
    cout << sumOfDigits(15121) << endl;

    return 0;
}