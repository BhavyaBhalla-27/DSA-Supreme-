// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
    int s = 0;
	int e = n-1;
	int m = 0;
	while(m<=e){
		if(arr[m]==0){
			swap(arr[m++],arr[s++]);
		}
		else if(arr[m]==1){
			m++;
		}
		else{
			swap(arr[m],arr[e]);
			e--;
		}
	}
    }
    
};