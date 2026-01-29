#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool ok=false;
    int i,j,freq[256],size,max;
    string line;

    for(i=0 ; i<256 ; i++) freq[i]=0;

    while(getline(cin,line))
    {
        if(ok) cout<<endl;
        ok=true;
        size = line.size();

        for(i=0,max=0 ; i<size ; i++)
        {
            freq[line[i]]++;
            if(freq[line[i]]>max) max = freq[line[i]];
        }

        for(i=1 ; i<=max ; i++)
        {
            for(j=255 ; j>=0 ; j--)
            {
                if(freq[j]==i)
                {
                    cout<<j<<" "<<freq[j]<<endl;
                    freq[j]=0;
                }
            }
        }
    }

	return EXIT_SUCCESS;
}
