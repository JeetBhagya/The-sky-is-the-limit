#include <bits/stdc++.h>
using namespace std;

int Queue[5];
int front=-1, rare=-1;
int cnt=0;

void push(int data)
{
	if(cnt>5) 
	{
		cout<<"Queue is full"<<endl;
		return;
	}
	Queue[rare%5+1]=data;
	rare++;
	cnt++;
}

int Top()
{
	if(cnt==0) 
	{
		cout<<"Queue is empty"<<endl;
		return -1;
	}
	return Queue[front%2+1];
}

void pop()
{
	if(cnt==0)
	{
		cout<<"Queue is empty"<<endl;
		return;
	}
	Queue[front%5+1]=-1;
	front++;
	cnt--;
}

int size()
{
	return cnt;
}

bool empty()
{
	return size();
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //        freopen("input.txt","r",stdin);
 //        freopen("output.txt","w",stdout);
 //    #endif
	
	push(6);
	push(7);
	push(8);
   	cout<<Top()<<endl;
   	push(9);
   	push(10);
   	pop();
   	cout<<Top()<<endl;
   	cout<<size()<<endl;
   	cout<<empty()<<endl;
}   