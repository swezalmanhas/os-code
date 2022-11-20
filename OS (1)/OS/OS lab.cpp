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
	
	//t=current time
	int t=0;
	
	for(int i=0;i<n;i++)
	{
		if(rembt[i]>0)
		{
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
}

void waitTime2(int p[],int n,int bt[],int wt[],int q)
{
	int rembt[n];
	
	for(int i=0;i<n;i++)
	{
		rembt[i]=bt[i];
	}
	
	//t=current time
	int t=0;
	
	//c=counter variable for no. of cycles
	int c=1;
	
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
		c++;
		if(done==1)
		break;
	}
	cout<<c-1<<endl;
}

void taTime(int p[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}

void avgTime1(int p[],int n,int bt[],int q)
{
	int wt[n],tat[n],totwt=0,tottat=0;
	waitTime(p,n,bt,wt,q);
	taTime(p,n,bt,wt,tat);
	for(int i=0;i<n;i++)
	{
		totwt+=wt[i];
		tottat+=tat[i];
	}
}
void avgTime2(int p[],int n,int bt[],int q)
{
	int wt[n],tat[n],totwt=0,tottat=0;
	waitTime2(p,n,bt,wt,q);
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
	int n=5;
	int p[n]={1,2,3,4,5};
	int bt[n]={5,6,7,8,9};
	int q1=2;
	int q2=3;
	avgTime1(p,n,bt,q1);
	avgTime2(p,n,bt,q2);
	return 0;
}
