#include<iostream>

using namespace std;

int evenDigits(long number) {
    if(number <= 9) return number % 2 == 0 ? number : 0;
    else {
        int last = number % 10;

        if(last % 2 != 0) last = 0;

        number = number / 10;

        int get = evenDigits(number);
        if(last != 0) get = get*10;
        last = get + last;

        return last;
    }
}

int main() {
    cout << evenDigits(8342116) << endl;
    cout << evenDigits(83116) << endl;
    cout << evenDigits(311) << endl;

    return 0;
}