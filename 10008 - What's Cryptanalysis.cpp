#include <iostream>

using namespace std;

int main()
{
    char c;
    int N,i,j,size,Occurence[26],max;

    for(i=0 ; i<26 ; i++) Occurence[i]=0;

    cin>>N;
    cin.get();

    for(i=0 ; i<N ; i++)
    {
        while(true)
        {
            c = cin.get();
            if(c=='\n') break;
            if(c>='a' && c<='z') Occurence[c-'a']++;
            if(c>='A' && c<='Z') Occurence[c-'A']++;
        }
    }
    for(i=0 ; i<26 ; i++)
    {
        for(j=0,max=0 ; j<26 ; j++)
        {
            if(Occurence[max]<Occurence[j])
            {
                max = j;
            }
        }
        if(Occurence[max]==0) break;
        cout<<(char)(max+'A')<<" "<<Occurence[max]<<endl;
        Occurence[max]=0;
    }
	return 0;
}
