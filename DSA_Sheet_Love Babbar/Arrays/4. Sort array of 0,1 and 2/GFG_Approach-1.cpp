class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        int zeroCount = 0;
       int oneCount = 0;
       int twoCount = 0;

       for(int i = 0;i<n;i++){
           if(nums[i] == 0){
               zeroCount++;
           }
           else if(nums[i] == 1){
               oneCount++;
           }
           else{
               twoCount++;
           }
       } 
       int i = 0;
       while(zeroCount--){
           nums[i] = 0;
           i++;
       }
       while(oneCount--){
           nums[i] = 1;
           i++;
       }    
       while(twoCount--){
           nums[i] = 2;
           i++;
       }
    }
};