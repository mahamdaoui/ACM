#include <iostream>

using namespace std;

int main() {

    int min,r,a[4][4];
    string o;

    while(cin>>a[1][1]>>a[1][2]>>a[1][3]>>a[2][1]>>a[2][2]>>a[2][3]>>a[3][1]>>a[3][2]>>a[3][3])
    {
        min = a[2][1]+a[3][1]+a[1][3]+a[3][3]+a[1][2]+a[2][2];
        o = "BCG";

        r = a[2][1]+a[3][1]+a[1][2]+a[3][2]+a[1][3]+a[2][3];
        if(r<min)
        {
            min = r;
            o = "BGC";
        }

        r = a[2][3]+a[3][3]+a[1][1]+a[3][1]+a[1][2]+a[2][2];
        if(r<min)
        {
            min = r;
            o = "CBG";
        }

        r = a[2][3]+a[3][3]+a[1][2]+a[3][2]+a[1][1]+a[2][1];
        if(r<min)
        {
            min = r;
            o = "CGB";
        }

        r = a[2][2]+a[3][2]+a[1][1]+a[3][1]+a[1][3]+a[2][3];
        if(r<min)
        {
            min = r;
            o = "GBC";
        }

        r = a[2][2]+a[3][2]+a[1][3]+a[3][3]+a[1][1]+a[2][1];
        if(r<min)
        {
            min = r;
            o = "GCB";
        }

        cout<<o<<" "<<min<<endl;
    }
    
    return 0;
}
