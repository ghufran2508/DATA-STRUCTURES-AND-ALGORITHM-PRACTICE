#include<iostream>

using namespace std;

void infinite_serires(int limit, int count = 0, int sum = 0) {
    if(count == limit) return;
    else {
        sum = sum + count;
        cout << sum  << " " ;
        

        infinite_serires(limit, count+1,sum);
    }
}

int main() {
    infinite_serires(10);

    return 0;
}