#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<bool>Sieve(int n){
    // Create a sieve
    vector<bool>sieve(n+1,true); // Mark every number as prime initially
    sieve[0] = sieve[1] = false; // As 0 and 1 are not prime
    // Optimization - 2 => Changing the outer for loop
    for(int i = 2;i<=sqrt(n);i++){ // 2 will be the first prime number
        if(sieve[i] == true){ 
            // int j = i*2; 
            // Optimization - 1
            int j = i * i;
            while(j<=n){
                sieve[j] = false; // Mark multiples of prime number as non prime
                j = j + i;
            }
        }
    }
    return sieve;
}
vector<bool>segSieve(int L,int R){
    // Using prime array to mark segmented sieve
    vector<bool>sieve = Sieve(sqrt(R));
    vector<int>basePrimes;
    // Step - 2
    for(int i = 0;i<sieve.size();i++){
        if(sieve[i] == true){
            // It is prime so push back in base primes
            basePrimes.push_back(i);
        }
    }
    // Step - 1
    vector<bool>segSieve(R-L+1,true);
    // Base Condition
    if(L == 1 || L == 0){
        segSieve[L] = false;
    }
    // Step - 3
    for(auto prime:basePrimes){
        int first_mul = (L/prime) * prime;
        if(first_mul < L){
            first_mul = first_mul + prime;
        }
        int j = max(first_mul,prime*prime); // Might be case that first_mul may be marked already
        // Exactly same loop as normal sieve
        while(j<=R){
            segSieve[j - L] = false; // Resemblance thing as 0th index is mapped to 110
            j = j + prime;
        }
    }
    return segSieve;
}
int main(){
    int L = 110;
    int R = 130;
    vector<bool>segmentedSieve = segSieve(L,R);
    for(int i = 0;i<segmentedSieve.size();i++){
        if(segmentedSieve[i]){
            cout<<i+L<<" ";
        }
    }
    return 0;
}