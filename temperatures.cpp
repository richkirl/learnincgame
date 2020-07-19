#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    const int n=4;
    int t[n]={5,-1,4,6};
    int m;
    m=t[0];
    for (int i = 1; i < n; i++) {
        if (abs(t[i])<abs(m) || t[i]==abs(m)) {
           m=t[i];
        }
        cout<<m<<endl;
    }
    return 0;
}
