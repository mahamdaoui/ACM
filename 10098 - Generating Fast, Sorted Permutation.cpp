#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int nbcase,i;
    string line,original;
    cin>>nbcase;
    getline(cin,line);

    for(i=0 ; i<nbcase ; i++)
    {
        getline(cin,line);
        sort(line.begin(),line.end());
        original = line;
        do
        {
            cout<<line<<endl;
            next_permutation(line.begin(),line.end());
        }while(line.compare(original)!=0);
        cout<<endl;
    }
	return 0;
}
