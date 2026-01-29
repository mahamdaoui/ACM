#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int count,i,nbcase,nb,invnb,sum;
    string nbs,sumsinv;

    cin>>nbcase;

    for(i=0 ; i<nbcase ; i++)
    {
        count = 0;
        cin>>nb;
        do
        {
            count++;

            ostringstream oss;
            oss<<nb;
            nbs = oss.str();
            reverse(nbs.begin(),nbs.end());
            istringstream iss(nbs);
            iss>>invnb;
            sum = invnb+nb;

            ostringstream sss;
            sss<<sum;
            nbs = sss.str();
            sumsinv = nbs;
            reverse(sumsinv.begin(),sumsinv.end());

            if(nbs.compare(sumsinv)==0) break;
            nb = sum;
        } while(true);
        cout<<count<<" "<<sum<<endl;
    }
	return 0;
}
