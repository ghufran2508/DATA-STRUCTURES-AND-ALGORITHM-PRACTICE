#include<iostream>

using namespace std;

int count_character(char* str, char c) {
    if(str[0] == '\0') return 0;
    else {
        int sum = 0;

        if(str[0] == c) sum++;

        sum += count_character(str+1, c);

        return sum;
    }
}

int main() {
    char str[10] = {'a', 'a','s','e','a','2','g','t','q','e'};
    cout << count_character(str, 'a') << endl;
    cout << count_character(str, 'e') << endl;

    return 0;
}