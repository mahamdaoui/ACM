#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
    int i,j,k,n,T[10000],freq[10],sum,size;
    string number;

    while(cin>>n)
    {
        sum=0;
        ostringstream oss;

        k=1;
        for(i=0 ; i<500 ; i++) T[i]=0;
        T[0]=1;
        for(i=2 ; i<=n ; i++)
        {
            for(j=0 ; j<k ; j++) T[j]= T[j]*i;
            for(j=0 ; j<k ; j++)
            {
                if(T[j]>=1000000)
                {
                    T[j+1] = T[j+1] + (T[j])/1000000;
                    T[j] = T[j]%1000000;
                    if(j==k-1) k++;

                }
            }
        }
        oss<<T[k-1];
        for(i=k-2 ; i>=0 ; i--) oss<<setw(6)<<setfill('0')<<T[i];
        number = oss.str();

        size = number.size();
        for(i=0 ; i<size ; i++) sum += (number[i]-'0');

        cout<<sum<<endl;
    }

	return 0;
}
