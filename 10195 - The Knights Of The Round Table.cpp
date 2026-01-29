#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
    double a,b,c,s;

    while(cin>>a>>b>>c)
    {
        if(a==0 || b==0 || c==0)
        {
            cout<<"The radius of the round table is: 0.000"<<endl;
            continue;
        }
        s = (a+b+c)/2;
        printf("The radius of the round table is: %0.3f\n",sqrt((s-a)*(s-b)*(s-c)/s));
    }

	return 0;
}
