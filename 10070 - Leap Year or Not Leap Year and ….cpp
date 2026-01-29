#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i,size,som,rest4,rest55;
    bool bulukulu,leap,huluculu,is400,f=true;
    string line;

    while(getline(cin,line))
    {
	if(f) 	f=false;
	else	cout<<endl;
        som=0;
        rest4=0;
        rest55=0;
        bulukulu = false;
        leap = false;
        huluculu = false;
        is400 = true;

        size = line.size();
        for(i=0 ; i<size ; i++) som += (line[i]-48);

        if(som%3==0 && (line[size-1]=='0' || line[size-1]=='5')) huluculu = true;
        for(i=0 ; i<size ; i++)
        {
            rest4  = (rest4 *10+line[i]-48)%4;
            rest55 = (rest55*10+line[i]-48)%55;

            if(i==size-3) if(rest4!=0) is400=false;
        }
        if(rest4==0 && (line[size-1]!='0' || line[size-2]!='0')) leap = true;
        if(rest4==0 && (line[size-1]=='0' && line[size-2]=='0') && is400) leap = true;
        if(leap && rest55==0) bulukulu=true;

        if(leap)         cout<<"This is leap year.\n";
        if(huluculu)     cout<<"This is huluculu festival year.\n";
        if(bulukulu)     cout<<"This is bulukulu festival year.\n";
        if(!leap && !huluculu && !bulukulu) cout<<"This is an ordinary year.\n";
    }
}
