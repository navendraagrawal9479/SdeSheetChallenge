#include <bits/stdc++.h>
using namespace std;

class minStack
{
	// Write your code here.
	stack<pair<int,int>>s;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(s.empty()){
                s.push({num,num});
            }
            else{
                int mini = s.top().second;
                mini = min(num,mini);
                s.push({num,mini});
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(s.empty())return -1;
            else{
                int el = s.top().first;
                s.pop();
                return el;
            }
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(s.empty())return -1;
            else{
                int el = s.top().first;
                return el;
            }
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(s.empty())return -1;
            else{
                int el = s.top().second;
                return el;
            }
		}
};class minStack
{
	// Write your code here.
	stack<pair<int,int>>s;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			// Write your code here.
            if(s.empty()){
                s.push({num,num});
            }
            else{
                int mini = s.top().second;
                mini = min(num,mini);
                s.push({num,mini});
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(s.empty())return -1;
            else{
                int el = s.top().first;
                s.pop();
                return el;
            }
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(s.empty())return -1;
            else{
                int el = s.top().first;
                return el;
            }
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
            if(s.empty())return -1;
            else{
                int el = s.top().second;
                return el;
            }
		}
};