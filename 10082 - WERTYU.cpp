#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i,j,size;
    string line,corr;

    corr = "'1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

    while(getline(cin,line))
    {
        size = line.size();
        for(i=0 ; i<size ; i++)
        {
            if(line[i]=='Q')
            {
                cout<<"\t";
                continue;
            }
            if(line[i]==' ') cout<<" ";
            for(j=0 ; j<46 ; j++)
            {
                if(line[i]==corr[j+1])
                {
                    cout<<corr[j];
                    break;
                }
            }
        }
        cout<<endl;
    }

	return 0;
}
