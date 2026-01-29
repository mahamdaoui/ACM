#include <iostream>

using namespace std;

int main()
{
    int reste,k,n;

    while(cin>>n)
    {
        reste=0;
        k=0;
        while(true)
        {
            k++;
            reste = (reste*10+1)%n;
            if(reste==0) break;
        }
        cout<<k<<endl;
    }
	return 0;
}
