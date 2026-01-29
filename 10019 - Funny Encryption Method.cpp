#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{
    int i,N,M,count,j,size;
    string db;

    cin>>N;
    for(i=0 ; i<N ; i++)
    {
        cin>>M;

        bitset<32> d_b(M);
        db = d_b.to_string<char,char_traits<char>,allocator<char> >();
        size = db.size();
        for(j=0,count=0 ; j<size ; j++)
        {
            if(db[j]=='1') count++;
        }
        cout<<count<<" ";

        ostringstream oss;
        oss<<M;
        istringstream iss(oss.str());
        iss>>hex>>M;
        bitset<32> h_b(M);
        db = h_b.to_string<char,char_traits<char>,allocator<char> >();
        size = db.size();
        for(j=0,count=0 ; j<size ; j++)
        {
            if(db[j]=='1') count++;
        }

        cout<<count<<endl;
    }
	return 0;
}
