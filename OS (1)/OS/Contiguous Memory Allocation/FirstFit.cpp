#include<bits/stdc++.h>
using namespace std;
void firstFit(int bs[],int m,int ps[],int n)
{
	int all[n];
	//stores block id of the block allocated to a process
	
	memset(all,-1,sizeof(all));
	//initially no block is assigned to any pr.
	
	for(int i=0;i<n;i++)//loop for processes
	{
		for(int j=0;j<m;j++)//loop to search blocksize
		{
			if(bs[j]>=ps[i])
			{
				all[i]=j;//allocate block j to process i
				bs[j]-=ps[i];//reduce avl mem in the block
				break;
				
			}
		}
	}
	cout<<"***FIRST FIT***\n";
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
	int m=5,n=4;
	int bs[m]={100,500,200,300,600};
	int ps[n]={212,417,112,426};
	firstFit(bs,m,ps,n);
	return 0;
}
