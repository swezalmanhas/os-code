#include<iostream>
using namespace std;

void waitTime(int p[],int n,int bt[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
}
void taTime(int p[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
	}
}

void avgTime(int p[],int n,int bt[])
{
	int wt[n],tat[n],totwt=0,tottat=0;
	waitTime(p,n,bt,wt);
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
	int n=3;
	int p[3]={1,2,3};
	int bt[3]={24,3,3};
	avgTime(p,n,bt);
	return 0;
}
