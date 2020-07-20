//#include "asciart.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cassert>
using namespace std;
int main()
{
    int L;
    int H;
    string T;
    fstream fs;
    fs.open ("asciart.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    assert(fs.is_open());
    fs >> L;
    fs >> H;
    fs >> T;
    cout<<L<<endl;
    cout<<H<<endl;
    cout<<T<<endl;
    //getline(fs, T);
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(fs, ROW);
        cout<<ROW<<endl;
    }
    fs.close();
    return 0;
}
