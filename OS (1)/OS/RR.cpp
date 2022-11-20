#include<iostream>
using namespace std;

void waitTime(int p[],int n,int bt[],int wt[],int q)
{
	int rembt[n];
	
	//initialization of rem. burst time as given b.t.
	for(int i=0;i<n;i++)
	{
		rembt[i]=bt[i];
	}
	int t=0;//t=current time
	
	while(1)
	{
		int done=1;
		for(int i=0;i<n;i++)
		{
			if(rembt[i]>0)
			{
				done=0;
				if(rembt[i]>q)
				{
					t+=q;
					rembt[i]-=q;
				}
				else
				{
					t+=rembt[i];
					wt[i]=t-bt[i];
					rembt[i]=0;
				}
			}
		}
		if(done==1)
		break;
	}
}
void taTime(int p[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}

void avgTime(int p[],int n,int bt[],int q)
{
	int wt[n],tat[n],totwt=0,tottat=0;
	waitTime(p,n,bt,wt,q);
	taTime(p,n,bt,wt,tat);
	cout<<"Processes\tBurst Time\tWaiting Time\tTurnaround Time\n";
	for(int i=0;i<n;i++)
	{
		totwt+=wt[i];
		tottat+=tat[i];
		cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"Average Waiting Time: "<<(float)totwt/(float)n<<endl;
	cout<<"Average Turnaround Time: "<<(float)tottat/(float)n<<endl;
}

int main()
{
	int n=6;
	int p[n]={1,2,3,4,5,6};
	int bt[n]={3,4,2,5,3,6};
	int q=2;
	avgTime(p,n,bt,q);
	return 0;
}
