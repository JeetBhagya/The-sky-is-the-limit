#include <bits/stdc++.h>
using namespace std;

stack<int>input;
stack<int>output;


//Approach 1

//input->output
//push data in input
//output->input
void push(int data)
{
	while(!input.empty())
	{
		output.push(input.top());
		input.pop();
	}
	input.push(data);
	while(!output.empty())
	{
		input.push(output.top());
		output.pop();
	}
}

//pop from input
void pop()
{
	input.pop();
}

//top of input
int top()
{
	return input.top();
}

//size of input
int size()
{
	return input.size();
}

//size=0 or not
bool empty()
{
	return size();
}

//Approach 2:

//push in input 
// void push(int data)
// {
// 	input.push(data);
// }

// //if output empty then push all elements in output from input and pop from output
// //if output is not empty pop from output
// void pop()
// {
// 	if(output.empty())
// 	{
// 		while(!input.empty())
// 		{
// 			output.push(input.top());
// 			input.pop();
// 		}
// 	}
// 	output.pop();
// }

// //if output empty then push all elements in output from input and return top of output
// //if output is not empty, return top of output
// int top()
// {
// 	if(output.empty())
// 	{
// 		while(!input.empty())
// 		{
// 			output.push(input.top());
// 			input.pop();
// 		}
// 	}
// 	return output.top();
// }

// //input and output size
// int size()
// {
// 	return output.size()+input.size();
// }

// //size=0 or not
// bool empty()
// {
// 	return size();
// }

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