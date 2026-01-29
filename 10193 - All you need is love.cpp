#include <iostream>
#include <bitset>
#include <string>

using namespace std;

unsigned long GCD(unsigned long a , unsigned long b)
{
    unsigned long t;
    while(b!=0)
    {
        t=b;
        b = a%b;
        a=t;
    }
    return a;
}

int main()
{
    unsigned long  nbcase,nb1,nb2,p=1;
    string number;

    cin>>nbcase;
    getline(cin,number);

    while(nbcase--)
    {
        getline(cin,number);
        bitset<32> b1(number);
        nb1 = b1.to_ulong();

        getline(cin,number);
        bitset<32> b2(number);
        nb2 = b2.to_ulong();

        if(GCD(nb1,nb2)<=1) cout<<"Pair #"<<p<<": Love is not all you need!"<<endl;
        else                cout<<"Pair #"<<p<<": All you need is love!"<<endl;

        p++;
    }
	return 0;
}
