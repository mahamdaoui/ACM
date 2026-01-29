#include <iostream>
#include <math.h>

using namespace std;

void sieve(bool *flag , int L , int U)
{
    double s;
    int i,j,d;
    d = U-L+1;

    for (i=0;i<d;i++) { flag[i]=true;}

    for (i=(L%2!=0);i<d;i+=2) { flag[i]=false; }
    s = sqrt(U);
    for (i=3;i<=s;i+=2)
    {
        if (i>L && !flag[i-L]) continue;
        j=L/i*i;
        if (j<L) j+=i;
        if (j==i) j+=i;
        j-=L;
        for (;j<d;j+=i) flag[j]=false;
    }
    if (L<=1) flag[1-L]=false;
    if (L<=2) flag[2-L]=true;
}


int main()
{
    int i,j,dd,min,maxi,mini,space,a,b,c,d,L,U;
    bool *prime;

    while(cin>>L>>U)
    {
        dd = U-L+1;
        prime = new bool[dd];
        sieve(prime,L,U);

        for(i=0 ; i<dd ; i++) if(prime[i]==true) break;

        mini = 1000000;
        maxi = 0;
        for(a=b=c=d=i,j=i,i=i+1; i<dd ; i++)
        {
            if(prime[i]==true)
            {
                space = i-j;
                if(space<mini)
                {
                    a = i;
                    b = j;
                    mini = space;
                }
                if(space>maxi)
                {
                    c = i;
                    d = j;
                    maxi = space;
                }
                j=i;
            }
        }
        if(a!=b)    cout<<L+b<<","<<L+a<<" are closest, "<<L+d<<","<<L+c<<" are most distant."<<endl;
        else        cout<<"There are no adjacent primes."<<endl;
    }

	return 0;
}
