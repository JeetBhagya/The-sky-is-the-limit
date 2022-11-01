#include <bits/stdc++.h>
using namespace std;

// //approach 1
// queue<int>q1;
// queue<int>q2;

// //first push in q2 
// //2nd push all the elements in q2 from q1
// //and swap q1 and q2=>push all elements in q1 from q2
// void push(int data)
// {
// 	q2.push(data);
// 	while(!q1.empty())
// 	{
// 		q2.push(q1.front());
// 		q1.pop();
// 	}
// 	swap(q1, q2);
// }

// //q1 front element poping
// void pop()
// {
// 	q1.pop();
// }

// // q1 front elements
// int top()
// {
// 	return q1.front();
// }

// //q1 size
// int size()
// {
// 	return q1.size();
// }

// //if size()!=0 =>true
// bool empty()
// {
// 	return size();
// }

//approach-2

queue<int>st;

void push(int data)
{
	int size=st.size();
	st.push(data);
	while(size--)
	{
		st.push(st.front());
		st.pop();
	}
}

void pop()
{
	st.pop();
}

int top()
{
	return st.front();
}

int size()
{
	return st.size();
}

bool empty()
{
	return st.empty();
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
   	cout<<top()<<endl;
   	push(9);
   	push(10);
   	pop();
   	cout<<top()<<endl;
   	cout<<size()<<endl;
   	cout<<empty()<<endl;
}   