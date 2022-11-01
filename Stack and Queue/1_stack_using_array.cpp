#include <bits/stdc++.h>
using namespace std;

int Stack[100];
int top=-1;
void push(int data)
{
	Stack[top+1]=data;
	top++;
}

int Top()
{
	return Stack[top];
}

void pop()
{
	top--;
}

int size()
{
	return top+1;
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