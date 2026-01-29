#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int N,i,a,b,c;
    bool is[3001],ok;
    while(cin>>N)
    {
        ok=true;
        if(N==1)
        {
            cin>>a;
            cout<<"Jolly"<<endl;
            continue;
        }
        for(i=0 ; i<N ; i++) is[i]=false;
        cin>>a;
        for(i=0 ; i<(N-1) ; i++)
        {
            cin>>b;
            c = abs(a-b);
            if(c>N || c<1 || is[c]==true) ok=false;
            else    is[abs(a-b)] = true;
            a = b;
        }
        for(i=1 ; i<N && ok==true ; i++)
        {
            if(is[i]==false)
            {
                ok=false;
                break;
            }
        }
        if(ok)    cout<<"Jolly"<<endl;
        else      cout<<"Not jolly"<<endl;
    }
	return 0;
}
