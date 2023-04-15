class Solution{
  public:
    long long merge(long long arr[],vector<long long>&temp,long long s,long long mid,long long e){
        long long i = s;
        long long j = mid + 1;
        long long k = s;
        long long invCount = 0;
        while(i<=mid && j<=e){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{ // Inversion count case
                temp[k++] = arr[j++];
                invCount += mid - i + 1;
            }
        }
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        while(j<=e){
            temp[k++] = arr[j++];
        }
        while(s<=e){
            arr[s] = temp[s];
            s++;
        }
        return invCount;
    }
    long long mergeSort(long long arr[],vector<long long>&temp,long long s,long long e){
        // Base condition
        if(s>=e){
            return 0;
        }
        long long mid = s + (e-s)/2;
        long long invCount = 0;
        // Recursive calls
        invCount += mergeSort(arr,temp,s,mid);
        invCount += mergeSort(arr,temp,mid+1,e);
        invCount += merge(arr,temp,s,mid,e);
        return invCount;
        
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long invCount = 0; //Counts inversion count
        vector<long long>temp(N,0); // for merging
        invCount = mergeSort(arr,temp,0,N-1); // merge sort function
        return invCount;
    }

};
