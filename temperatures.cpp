//#include "temperatures.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    //int m=0,tmp=0;
    const int n=4; // the number of temperatures to analyse
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
