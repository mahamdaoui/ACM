#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int MS[101][101],n,m,i,j,count=0;
	string line;
	cin>>n>>m;	
	do
	{
	    count++;
	    if(n==0 && m==0) break;
	    getline(cin,line);

	    for (i=0 ; i<100 ; i++)   fill_n(MS[i],100,0);
	    for(i=0 ; i<n ; i++)
	    {
	        getline(cin,line);
	        for(j=0 ; j<m ; j++)
	        {
	            if(line[j]=='*')
	            {
	                MS[i][j]=-1;
	                if(j!=0) if(MS[i][j-1]!=-1)       MS[i][j-1]++;
	                if(j!=(m-1)) if(MS[i][j+1]!=-1)   MS[i][j+1]++;
	                if((i+1)<n)
	                {
	                    if(MS[i+1][j]!=-1)   MS[i+1][j]++;
                        if(j!=0) if(MS[i+1][j-1]!=-1) MS[i+1][j-1]++;
                        if(j!=(m-1)) if(MS[i+1][j+1]!=-1) MS[i+1][j+1]++;
	                }
                    if((i-1)>=0)
                    {
                        if(MS[i-1][j]!=-1)   MS[i-1][j]++;
                        if(j!=0) if(MS[i-1][j-1]!=-1) MS[i-1][j-1]++;
                        if(j!=(m-1)) if(MS[i-1][j+1]!=-1) MS[i-1][j+1]++;
                    }
	            }
            }
	    }

        cout<<"Field #"<<count<<":"<<endl;
	    for(i=0 ; i<n ; i++)
	    {
	        for(j=0 ; j<m ; j++)
	        {
	            if(MS[i][j]!=-1)    cout<<MS[i][j];
	            else                cout<<'*';
	        }
	        cout<<endl;
	    }
	    cin>>n>>m;
	    if(n!=0 || m!=0) cout<<endl;

	} while(true);

	return 0;
}
