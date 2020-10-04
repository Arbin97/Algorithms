
//		   Array Rotation Implementation

//       C++ implementation of a right rotation of an array by K units

//       Right rotation of an array means shifting the element by k units to it's right in a circular fashion without loosing the values present inside the array

//       Eg:    Original arr={1,5,2,4,3}  k= 3
//       Right-Rotated arr={2,4,3,1,5};
       
   
//There are three approaches we will be taking to solve this problem where we will be going from the worst time complexity solution to the best optmized time complexity.

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void display(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    	cout<<arr[i]<<" ";
    cout<<endl;
}

// Method 1:  Rotation of array k times

void method1(vector<int>arr,int k)
{
	int n= arr.size();
	
	while(k--)
	{
	    int temp =arr[n-1];
	    
	    for(int i=n-1;i>=1;i--)
	    {
	    	arr[i]= arr[i-1];
	    }
	    arr[0]= temp;
	}
	
	
	display(arr);
	
	// Time Complexity = O(n*k) and if k<=n it will be 0(n2) 
	// Space Complexity = 0(1) we are not using any extra array to store
	
	// Problem: what if k=10^18 or 10^9 the no of iteration will surely reach TLE and thus not well optimized if K is large. 
}

// Method 2: use of circular property and remainder approach

void method2(vector<int>arr,int k)
{
    //  if we carefully observe then the rotated array at k=3 when N= 5( size of array) will be same as the rotated array when k= 8,13,18.....
    // which means ther the rotation is circular so the rotated array when k=12 will be equivalent to the rotated array when k=2 given N=5.
   //  therefore rotation by k units equals to the rotation by (k%N) units which will reduce the index out of bound problem and we can get the rotated array at the first valid value of K%N.
     
     //so the problem will be optmized down to O(n)
     
     int n=arr.size();
     
     k= k%n;   // to reduce down the value of k.
     
     vector<int>temp(n);
     
     for(int i=0;i<n;i++)
     {
     	temp[(i+k)%n]= arr[i];
     }
     
     display(temp);
     
     
     // Time complexity : 0(N) 
     // Space complexity: o(N) we are using temp array to store the values
     
     // Problem : we are using extra space so let's get rid of it .        
}

// Method 3: reverse concept

void method3(vector<int>arr,int k)
{
     // {1,5,2,4,3}  k =3
    // reverse the arr from k to n     {3,4,2} 
    // reverse the arr from 0 to k      {5,1}                  updated arr: {5,1,3,4,2}
    // reverse the whole array from o to n  {2,4,3,1,5}          rotated by k units 
    


    reverse(arr.begin(),arr.end());
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.end());
   
    
    
    display(arr);
    
    // Time Complexity= O(N) for reversing 
    // Space Complexity= O(1)   
    // The most optimised solution for right rotation of array
}



int32_t main()
{
int n,k;

cin>>n>>k;

vector<int>arr(n);

for(int i=0;i<n;i++) cin>>arr[i];

method1(arr,k);
method2(arr,k);
method3(arr,k);

return 0;
}




	    
	     
  
