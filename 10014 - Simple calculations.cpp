#include<iostream>

using namespace std;

int main()
{
    double a0,an,c[3000],s;
    int n,cases;
    cin>>cases;
    for(int i=0;i<cases;i++)
    {
        cin>>n;
        cin>>a0>>an;
        for(int j=1;j<=n;j++)
        {
            cin>>c[j];
        }
        s=0;
        for(int j=1;j<=n;j++)
        {
            s=s+c[j]*(n-j+1);
        }

        s=s*(-2);
        s=s+n*a0+an;
        s=(double)s/(n+1);
        printf("%0.2lf\n",s);
        if((cases-1) != i)
        {
            cout <<endl;
        }
    }
    return 0;
}
