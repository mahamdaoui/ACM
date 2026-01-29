#include <iostream>

using namespace std;

int main()
{
    bool D[3653];
    int i,j,k,T,N,P,h,sum;

    cin>>T;
    for(i=0 ; i<T ;i++)
    {
        cin>>N;
        cin>>P;
        for(j=1 ; j<=N ; j++)    D[j]=true;
        for(j=0 ; j<P ; j++)
        {
            cin>>h;
            for(k=h ; k<=N ; k=k+h) D[k]=false;
        }

        for(j=6 ; j<=N ; j=j+7)
        {
            D[j]=true;
            D[j+1]=true;
        }

        for(j=1,sum=0 ; j<=N ; j++) if(D[j]==false) sum++;
        cout<<sum<<endl;
    }
	return 0;
}
