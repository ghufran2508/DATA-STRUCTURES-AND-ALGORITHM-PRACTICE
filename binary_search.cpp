#include<iostream>

using namespace std;

#define SIZE 10

int main(){

    int data[SIZE]={20,45,66,77,100,134,345,567,666,890};   // Data needs to be sorted

    int t,b,mid;
    t=SIZE-1;
    b=0;

    int sv=567;

    int i=0;
    while (b<=t){
        mid=(b+t)/2;
        if (sv == data[mid])
            b=t+1;
        else if (sv < data[mid])
            t = mid - 1;
        else
            b = mid + 1;

        i++;
    }
    if (sv==data[mid])
        cout << "Found in "<<i<<" steps at index "<<mid<<"\n";
    else
        cout << "Not found in "<<i<<" steps\n";
}
