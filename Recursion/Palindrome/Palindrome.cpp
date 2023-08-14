#include <iostream>
using namespace std;

bool rec(string abc, int start, int end){
    if(start >= end) return true;
    if(abc[start] == abc[end]){
        return rec(abc,start+1,end-1);
    } else {
        return false;
    }
}

int main()
{
    cout << rec("NITIN",0,4);
    return 0;
}