#include <iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
//choose the pivot

int pivot=arr[high];
//Index of smaller element and Indicate
//the right position of pivot found so far
int i=(low-1);

for(int j=low;j<=high;j++)
{
	//If current element is smaller than the pivot
	if(arr[j]<pivot)
	{
	//Increment index of smaller element
	i++;
	swap(arr[i],arr[j]);
	}
}
swap(arr[i+1],arr[high]);
return (i+1);
}

// The Quicksort function Implement
			
void quickSelect(int arr[],int low,int high)
{
// when low is less than high
if(low<high)
{
	// pi is the partition return index of pivot
	int pi=partition(arr,low,high);
	int L_size = pi - low;

  if ( k-1 == L_size ) {
    return arr[pi];
  }

  if ( k-1 < L_size ) {
    return quickSelect(arr,low,pi-1);
  } else {
    k = k - pi + low -1;
	  return quickSelect(arr,pi+1,high);
  }
	//Recursion Call
	//smaller element than pivot goes left and
	//higher element goes right
}
}
			

int main() {
int arr[]={10,7,8,9,1,5};
int n=sizeof(arr)/sizeof(arr[0]);
// Function call
quickSort(arr,0,n-1);
//Print the sorted array
cout<<"Sorted Array\n";
for(int i=0;i<n;i++)
{
	cout<<arr[i]<<" ";
}
return 0;
}
// This Code is Contributed By Diwakar Jha
