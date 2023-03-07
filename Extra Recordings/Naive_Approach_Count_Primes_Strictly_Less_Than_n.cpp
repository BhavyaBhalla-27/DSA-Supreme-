#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n == 0 || n == 1) // 0 and 1 are not primes as 2 is the smallest prime    
        return false; // return false as they are not prime 
    for(int i = 2;i<n;i++){ // Run a loop from 2 to n-1 (strictly less than n)
        if(n%i==0){ // If factor found, return false
            return false;
        }
    }
    return true; // If no factor found, simply return true
}
int countPrimes(int n){
    int count = 0;
    for(int i = 2;i<n;i++){
        if(isPrime(i)) // Check for prime or not
            count++; // If prime then increment the count 
    }
    return count; // at end return how many prime number found
}
int main(){
    int n = 5;
    int ans = countPrimes(n);
    cout<<ans<<endl;
    return 0;
}