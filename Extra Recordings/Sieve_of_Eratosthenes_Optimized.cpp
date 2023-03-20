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
int main(){
    vector<bool>sieve = Sieve(25);
    // Print all prime numbers now
    for(int i = 0;i<=25;i++){
        if(sieve[i] == true){
            // i is prime
            cout<<i<<" "; 
        }
    }
    return 0;
}