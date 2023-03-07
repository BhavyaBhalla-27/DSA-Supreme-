// Used to find the number of primes strictly less than n
#include<iostream>
#include<vector>
using namespace std;
int countPrimes(int n){
    if(n == 0) 
        return 0;
    vector<bool>prime(n,true); // Initially all are marked as prime
    prime[0] = false; // 0 is non-prime
    prime[1] = false; // 1 is non-prime
    int count = 0; // initially no prime number
    for(int i = 2;i<n;i++){ 
        if(prime[i]){ // If it is marked prime, then just make all the multiples of that number as non prime
            count++; // Increase count as we found prime
            int j = 2*i; 
            while(j<n){
                prime[j] = false; // Mark as non-prime the multiples of prime number 
                j = j + i;
            }
        }
    }
    return count; // Return the number of primes
}
int main(){
    int n = 21;
    int ans = countPrimes(n);
    cout<<ans;
    return 0;
}