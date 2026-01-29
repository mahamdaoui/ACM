#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

typedef vector<int>::iterator It;

int main()
{
    int p,q,max=0,N;
    vector<int> P;
    ifstream in("number3.in");
    ofstream out("number3.out");

    P.resize(10002);

    if( in && out)
    {
        for(int i=1 ; i<=10000 ; i++)
        {
            p=0;
            q = i;
            do
            {
                p++;
                if(q==1) break;
                if(q%2!=0) q = 3*q+1;
                else q /= 2;
            } while(true);
            P[i]=p;
        }

        while(in>>p>>q)
        {
            max=0;
            for(It it1=(P.begin()+p) ; it1!=(P.begin()+q) ; it1++)
            {
                if(*it1>max) max=*it1;
            }
            out<<setw(6)<<p<<" "<<setw(6)<<q<<" "<<setw(6)<<max<<endl;
        }
    }

	return 0;
}
