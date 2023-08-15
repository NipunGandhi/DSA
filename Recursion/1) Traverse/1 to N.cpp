#include <iostream>
using namespace std;

void rec(int n){
    if(n==0) return;
    rec(n-1);
    cout<<n<<endl;
}

int main()
{
    rec(5);
    return 0;
}