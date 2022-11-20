#include<iostream>
using namespace std;
int main()
{
	int page[50],i,n,f,ps,off,pno;
	int ch=0;
	cout<<"Enter the no. of pages in memory\n";
	cin>>n;
	cout<<"Enter page size\n";
	cin>>ps;
	cout<<"Enter the no. of frames\n";
	cin>>f;
	for(i=0;i<n;i++)
	{
		page[i]=-1;
	}
	cout<<"Enter the page table\n";
	cout<<"(Enter frame no as -1 if that page is not present in any frame)\n";
	cout<<"Page no.\tFrame no.\n";
	for(i=0;i<n;i++)
	{
		cout<<i<<"\t\t";
		cin>>page[i];
	}
	do
	{
		cout<<"Enter logical address\n";
		cin>>pno;
		cin>>off;
		if(page[pno]==-1)
		{
			cout<<"The required page is not available in any of the frames\n";
		}
		else
		{
			cout<<"Frame no: "<<page[pno]<<" Offset: "<<off<<endl;
		}
		cout<<"Do you wish to continue?(1/0)\n";
		cin>>ch;
	}
	while(ch==1);
	return 0;
}
