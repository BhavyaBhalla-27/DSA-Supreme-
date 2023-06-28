//

class Solution {
public:
    int strStr(string s1, string s2) {
        // Method - 1 (Using Inbuilt function)
        // int ans = s1.find(s2);
        // return ans;

        // Method - 2 (Using Sliding Window Approach)
        int n = s1.length();
        int m = s2.length();
        for(int i = 0;i<=n-m;i++){
            for(int j = 0;j<m;j++){
                if(s2[j] != s1[i+j])
                    break;
                if(j==m-1)
                    return i;
            }
        }
        return -1;
    }
};