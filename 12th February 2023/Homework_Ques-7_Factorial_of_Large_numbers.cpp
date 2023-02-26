#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void factorial(int N){
    vector<int>ans;
    ans.push_back(1); // Initally push 1 in the array
    int carry = 0;  // Initially carry is taken as 0
    for(int i = 2;i<=N;i++){ // Traverse 2 to the number 
        for(int j = 0;j<ans.size();j++){
            // Formulae done in dry case
            int x = ans[j] * i + carry; 
            ans[j] = x%10;
            carry = x/10;
        }
        // If carry is of multiple digits then store carry digit by digit
        while(carry){
            ans.push_back(carry%10);
            carry = carry/10;
        }
        carry = 0; // Again put carry to 0
    }
    reverse(ans.begin(),ans.end()); // reverse the answer first and then display
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}
int main(){
    factorial(50);
    return 0;
}