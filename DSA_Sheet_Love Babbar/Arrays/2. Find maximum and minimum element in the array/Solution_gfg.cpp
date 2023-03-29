// GFG Question Link - https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1

struct pair getMinMax(long long int arr[], long long int n) {
    struct pair p; // Making a structure named p
    // Using dot (.) we can access the elements of the structure
    p.min = arr[0];
    p.max = arr[0];
    // Run a loop for all the elements
    for(int i=0; i<n; i++)
    {
        // If we found an element greater than current max then just update it
        if(arr[i]>p.max)
        {
            p.max = arr[i];
        }
        // If we found an element lesser than current min then just update it
        if(arr[i] < p.min) 
        {
            p.min = arr[i];
        }
    }
    return p; // Return the structure as return type of function was structure
}