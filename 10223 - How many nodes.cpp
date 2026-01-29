#include <iostream>

using namespace std;

void catalan(long long *t)
{
    long long i=1;
    t[1]=1;
    while(true)
    {
        t[i+1] = (2*t[i]*(2*i+1))/(i+2);
        i++;
        if(t[i]>4294967295LL) break;
    }
}


int main()
{
    int i;
    long long cat[21],n;

    catalan(cat);

    while(cin>>n)
    {
        for(i=0 ; i<20; i++)
        {
            if(cat[i]==n)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
	return 0;
}
