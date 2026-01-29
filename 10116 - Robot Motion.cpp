#include <iostream>

using namespace std;

int main()
{
    int i,j,a1,a2,r,c,step,ok;
    char M[12][12],k;

    while(true)
    {
        cin>>a1>>a2>>c;
        if(a1==0 && a2==0 && c==0) break;
        cin.get();
        for(i=1,r=1,step=0,ok=0; i<=a1 ; i++)
        {
            for(j=1 ;j<=a2 ; j++)   M[i][j] = cin.get();
            cin.get();
        }
        while(true && !ok)
        {
            k = M[r][c];
            M[r][c] =(char)(step+'0');
            if(k=='W')
            {
                step++;
                if(c==1)    ok=1;
                else
                {
                    if(M[r][c-1]!='E' && M[r][c-1]!='W' && M[r][c-1]!='S' && M[r][c-1]!='N')    ok=2;
                    c -=1;
                }
            }
            if(k=='E')
            {
                step++;
                if(c==a2)   ok=1;
                else
                {
                    if(M[r][c+1]!='E' && M[r][c+1]!='W' && M[r][c+1]!='S' && M[r][c+1]!='N')    ok=2;
                    c +=1;
                }
            }
            if(k=='N')
            {
                step++;
                if(r==1)    ok=1;
                else
                {
                    if(M[r-1][c]!='E' && M[r-1][c]!='W' && M[r-1][c]!='S' && M[r-1][c]!='N')    ok=2;
                    r -=1;
                }
            }
            if(k=='S')
            {
                step++;
                if(r==a1)   ok=1;
                else
                {
                    if(M[r+1][c]!='E' && M[r+1][c]!='W' && M[r+1][c]!='S' && M[r+1][c]!='N')    ok=2;
                    r +=1;
                }
            }
        }
        if(ok==1)
        {
            if(step!=1)         cout<<step<<" steps to exit"<<endl;
            else                cout<<step<<" step to exit"<<endl;
        }
        if(ok==2)
        {
            if((M[r][c]-'0')!=1 && (step-(M[r][c]-'0'))!=1) cout<<(M[r][c]-'0')<<" steps before a loop of "<<step-(M[r][c]-'0')<<" steps"<<endl;
            if((M[r][c]-'0')==1 && (step-(M[r][c]-'0'))!=1) cout<<(M[r][c]-'0')<<" step before a loop of "<<step-(M[r][c]-'0')<<" steps"<<endl;
            if((M[r][c]-'0')!=1 && (step-(M[r][c]-'0'))==1) cout<<(M[r][c]-'0')<<" steps before a loop of "<<step-(M[r][c]-'0')<<" step"<<endl;
            if((M[r][c]-'0')==1 && (step-(M[r][c]-'0'))==1) cout<<(M[r][c]-'0')<<" step before a loop of "<<step-(M[r][c]-'0')<<" step"<<endl;
        }

    }
	return 0;
}
