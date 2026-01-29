#include <iostream>

using namespace std;

int main()
{
    long long a,b,c;
    while(cin>>a>>b )
    {
        c = a-b;
        if(c>0) cout<<c;
        else cout<<-c;
        cout<<endl;
    }
}
