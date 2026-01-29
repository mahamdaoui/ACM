#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double s;
    long long i,n,k;

    while(cin>>n>>k)
    {
        if(n==k || k==0) cout<<1<<endl;
        else
        {
            k = ((n-k)>k ? (n-k) : k);
            for(i=k+1,s=0 ; i<=n; i++)
            {
                s += (log10(i)-log10(n-i+1));
            }
            cout<<floor(s)+1<<endl;
        }
    }

	return 0;
}
