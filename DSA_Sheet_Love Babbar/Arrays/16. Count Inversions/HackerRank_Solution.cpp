// https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_r=internal-search

long merge(vector<int>&arr,vector<int>&temp,long s,long mid,long e){
        long i = s;
        long j = mid + 1;
        long k = s;
        long invCount = 0;
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
    long mergeSort(vector<int>&arr,vector<int>&temp,long s,long e){
        // Base condition
        if(s>=e){
            return 0;
        }
        long mid = s + (e-s)/2;
        long invCount = 0;
        // Recursive calls
        invCount += mergeSort(arr,temp,s,mid);
        invCount += mergeSort(arr,temp,mid+1,e);
        invCount += merge(arr,temp,s,mid,e);
        return invCount;
        
    }

long countInversions(vector<int> arr) {
    long invCount = 0;
    vector<int>temp(arr.size(),0);
    invCount = mergeSort(arr, temp, 0, arr.size() - 1);
    return invCount;
}