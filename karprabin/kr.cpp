#include <iostream>
#include <string.h>
using namespace std;
#define d 256
#define q 101
int main()
{
	char rp[10];
	char rt[50];
	int p,t,h;
	p=t=0;
	h=1;
	cout<<"Enter text string";
	cin>>rt;
	cout<<"Enter pattern string";
	cin>>rp;
	int i;
	int m = strlen(rp);
	int n=strlen(rt);
	for(i=0;i<m-1;i++)
	{
		h=(h*d)%q;
	}
	//cout<<h;
    for(i=0;i<m;i++)
    {
        p=(d*p+rp[i])%q;
        t=(d*t+rt[i])%q;
    }

    for(i=0;i<=n-m;i++)
    {
    	if(p==t)
    	{
    		int j;
    		for(j=0;j<m;j++)
    		{
    			if(rt[i+j]!=rp[j])
    			{
    				break;
    			}
    		}
    		if(j==m)
    		{
    			cout<<"Pattern found at location : "<<i<<endl;
    		}
    	}
    	if(i<n-m)
    	{
    		t=(d*(t - rt[i]*h) + rt[i+m])%q;
    		if(t<0)
    		{
    			t=t+q;
    		}
    	}
    }
}
