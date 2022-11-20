#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,k;
	n=5;
	m=3;
	//allocated
	int alloc[n][m]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
	//maximum
	int max[n][m]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	//available resources
	int av[m]={3,3,2};
	//f=finish(whether a process is finished or not)
	
	
	int f[n],ss[n],index=0;
	//set finish of all processes to 0
	for(k=0;k<n;k++)
	{
		f[k]=0;
	}
	int need[n][m];
	//calculate need
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
	int y=0;
	for(k=0;k<n;k++)
	{
		//i=loop for processes
		for(i=0;i<n;i++)
		{
			if(f[i]==0)
			{
				int flag=0;
				for(j=0;j<m;j++)
				{
					if(need[i][j]>av[j])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)//resources can be granted
				{
					ss[index++]=i;
					//y=loop for available res.
					for(y=0;y<m;y++)
					{
						av[y]+=alloc[i][y];
					}
					f[i]=1;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<ss[i]<<" ";
	}
}
