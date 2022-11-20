#include<bits/stdc++.h>
using namespace std;
void nextFit(int bs[],int m,int ps[],int n)
{
	int all[n];
	int j=0;
	//stores block id of the block allocated to a process
	
	memset(all,-1,sizeof(all));
	//initially no block is assigned to any pr.
	
	for(int i=0;i<n;i++)//loop for processes
	{
		while(j<m)//loop to search blocksize
		{
			if(bs[j]>=ps[i])
			{
				all[i]=j;//allocate block j to process i
				bs[j]-=ps[i];//reduce avl mem in the block
				break;
				
			}
			j=(j+1)%m;
		}
	}
	cout<<"***NEXT FIT***\n";
	cout<<"P no.\tP Size\tBlock no.\n";
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<ps[i]<<"\t";
		if(all[i]!=-1)
		{
			cout<<all[i]+1;
		}
		else
		{
			cout<<"Not allocated";
		}
		cout<<endl;
	}
}

int main()
{
	int m=3,n=3;
	int bs[m]={5,10,20};
	int ps[n]={10,20,5};
	nextFit(bs,m,ps,n);
	return 0;
}
