#include<iostream>
#include<conio.h>

using namespace std;

void Heapsort(int a[],int n);

void Heapify(int a[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[largest])
	largest=l;
	if(r<n && a[r]>a[largest])
	largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		Heapify(a,n,largest);
	}
}

void Heapsort(int a[],int n)
{
	for(int i=n/2;i>=0;i--)
	Heapify(a,n,i);
	cout<<"Max heap is"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
}

int main()
{
	int n;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	void Heapsort(int a,int n)
	{
		for(i=n-1;i>=0;i--)
		swap(a[0],a[i]);
		Heapify(a,i,0);
		cout<<"Sorted heap is"<<endl;
    	for(int i=0;i<n;i++)
     	{
		cout<<a[i];
    	}
 	}
	
return 0;	
}
