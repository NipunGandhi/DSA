#include <iostream>

using namespace std;

int rec(int n){
    if(n == 0 || n == 1) return n;
    int fact = rec(n-1) + rec(n-2);
    return fact;
}

int main()
{
    cout << rec(10);
    return 0;
}