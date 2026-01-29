#include <iostream>

using namespace std;

int main()
{
    long long n;
    while(true)
    {
        cin>>n;
        if(n<0) break;
        cout<<(n+n*n+2)/2<<endl;
    }
	return 0;
}
