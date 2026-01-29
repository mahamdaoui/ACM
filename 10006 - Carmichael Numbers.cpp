#include <iostream>

using namespace std;

int main() {
    int i,a,carm[15] ={561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};

    while(1)
    {
        cin>>a;
        if(a==0) break;
        for(i=0 ; i<15 ; i++)
        {
            if(carm[i]==a)
            {
                cout<<"The number "<<a<<" is a Carmichael number.\n";
                break;
            }
        }
        if(i>=15) cout<<a<<" is normal.\n";
    }
    return 0;
}