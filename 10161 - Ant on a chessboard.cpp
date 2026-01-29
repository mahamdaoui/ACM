#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    ofstream coutt("test.txt");
    ifstream cinn("test.in");
    int N,R,K,X,Y;



    do
    {
        cinn>>K;
        if(K==0) break;
        N = (int) sqrt(K);
        R = K - N*N;

        if (N%2!=0)
        {
            if(R==0)
            {
                X = 1;
                Y = N;
            }
            else
            {
                if(R>N+1)
                {
                    Y = 2*N+2-R;
                    X = N+1;
                }
                else
                {
                    Y = N+1;
                    X = R;
                }
            }
        }
        else
        {
            if(R==0)
            {
                X = N;
                Y = 1;
            }
            else
            {
                if(R>N+1)
                {
                    X = 2*N+2-R;
                    Y = N+1;
                }
                else
                {
                    X = N+1;
                    Y = R;
                }
            }
        }
        coutt<<K<<endl<<X<<" "<<Y<<endl;
    }while(true);

	return 0;
}
