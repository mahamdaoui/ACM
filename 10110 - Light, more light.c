#include <stdio.h>

int main()
{
    int N,ok,i;

    do
    {
        ok=0;
        scanf("%d",&N);
        if(N==0) break;
        for(i=1 ; i*i<=N ; i++)
        {
             if(i*i==N)
             {
                 ok=1;
                 printf("yes\n");
             }
        }
        if(!ok) printf("no\n");
    } while(1);
	return 0;
}
