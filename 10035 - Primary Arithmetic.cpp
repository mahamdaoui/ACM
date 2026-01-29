#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void traite(int,int&,int&);

int main()
{
	unsigned int N,M;
	int i,j,k,carry,nbcarry,size;
	string line,nbr1,nbr2;

	while(cin>>N>>M)
	{
		ostringstream oss1,oss2;
		oss1<<N;
		oss2<<M;

		if(N==0 && M==0 ) break;
		nbr1 = oss1.str();
		nbr2 = oss2.str();

		nbcarry = 0;
		carry = 0;

        reverse(nbr1.begin(),nbr1.end());
        reverse(nbr2.begin(),nbr2.end());

        size = ((nbr1.size() < nbr2.size() ? nbr2.size() : nbr1.size()));

		for( i = 0 ; i<size ; i++)
		{
			if(i<nbr2.size() && i<nbr1.size())
			{
				k = (nbr1[i]+nbr2[i]-96+carry);
				traite(k,carry,nbcarry);
			}
			else
			{
				if(i>=nbr1.size())
				{
					k = nbr2[i]+carry-48;
					traite(k,carry,nbcarry);
				}
				if(i>=nbr2.size())
				{
					k = nbr1[i]+carry-48;
					traite(k,carry,nbcarry);
				}
			}
		}
		if(nbcarry!=0)
		{
		    if(nbcarry==1) cout<<nbcarry<<" carry operation."<<endl;
		    else           cout<<nbcarry<<" carry operations."<<endl;
		}
		else cout<<"No carry operation."<<endl;
	}
	return 0;
}

void traite(int k,int &carry, int &nbcarry)
{
    if(k>=10)
    {
        carry = k/10;
        nbcarry++;
    }
    else carry =0;
}